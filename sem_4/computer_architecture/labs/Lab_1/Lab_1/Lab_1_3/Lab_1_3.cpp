// Lab_1_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
	Нужно распараллелить умножение матриц. 
	План такой: выдадим всем потокам равное число столбцов первой матрицы и строк второй
	Каждый элемент этого столбца умнож на каждый элемент этой строки и записывается в матрицу локального результата
	Один элемент первой матрицы формирует отдельную строку
	В конце для каждого элемента проводится команда Reduce

	Примечание: для удобства отправки стоит транспонировать первую матрицу (поменять столбцы и строки местами)
	*/
#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int myrank, n;
	int K, L, M;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	
	double time_work = MPI_Wtime();
	if (myrank == 0) {
		K = atoi(argv[1]);
		L = atoi(argv[2]);
		M = atoi(argv[3]);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Bcast(&K, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	vector<double> result_component(n * K * M);

	//делим на столбцы
	vector<double> v1(K * L);
	vector<double> transp_v1(L * K);
	//делим на строки
	vector<double> v2(L * M);

	vector<double> local_v1(L * K);
	vector<double> local_v2(L * M);

	vector<double> local_result(K * M);
	vector<double> global_result(K * M);
	//generate matrix
	if (myrank == 0) {
		int temp;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < L; j++) {
				temp = -(rand() % 2);
				v1[i * L + j] = temp;
				transp_v1[j * K + i] = temp;
				cout << temp << " ";
			}
			cout << "\n";
		}

		cout << "\n\n";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < M; j++) {
				temp = -(rand() % 2);
				v2[i * M + j] = temp;
				cout << temp << " ";
			}
			cout << "\n";
		}
	}
	/*
	//let L mod n == 0
	int n1 = L / n;  //	число строк, получаемых каждым потоком
	MPI_Scatter(transp_v1.data() + myrank * n1 * K,
		K * n1,
		MPI_DOUBLE,
		local_v1.data() + myrank * n1 * K,
		K * n1,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);

	MPI_Scatter(v2.data() + myrank * n1 * M,
		M * n1,
		MPI_DOUBLE,
		local_v2.data() + myrank * n1 * M,
		M * n1,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
	
	//считаем локальный результат
	//для каждой строки перемнож каждый с каждым и складываем в сумму 
	
	for (int p = myrank * n1; p < (myrank + 1) * n1; p++) {
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < M; j++) {
				local_result[i * M + j] += local_v1[p * K + i] * local_v2[p * M + j];
			}
		}
	}

	MPI_Gather(local_result.data(), K * M, MPI_DOUBLE, result_component.data() + myrank * K * M, K * M, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	*/

	//L % n != 0
	
	/*
	n = 2;
	myrank = 1;
	transp_v1 = {
		0, 0,
		0, 0,
		0, 0,
		0, 0,
		-1, -1,
		0, -1
	};

	v2 = {
		0, 0,
		0, 0,
		0, 0,
		-1, 0,
		-1, 0,
		0, 0
	};
*/	
	int n1 = L / n;
	int n2 = L % n;

	vector<int> sendcounts(n);
	vector<int> line_count(n);
	vector<int> displs(n);
	vector<int> line_displs(n);
	int counter = 0;
	int line_counter = 0;
	if (n == 1) {
		sendcounts[0] = L * K;
		displs[0] = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			int d = i < n2 ? n1 + 1 : n1;
			line_count[i] = d;
			d *= K;
			sendcounts[i] = d;
			displs[i] = counter;
			line_displs[i] = line_counter;
			counter += d;
			line_counter += line_count[i];
		}
	}
	MPI_Scatterv(transp_v1.data(), 
		sendcounts.data(), 
		displs.data(), 
		MPI_DOUBLE, 
		local_v1.data() + displs[myrank],
		sendcounts[myrank], 
		MPI_DOUBLE, 
		0, 
		MPI_COMM_WORLD);

	counter = 0;
	if(n == 1) {
		sendcounts[0] = L * M;
		displs[0] = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			int d = i < n2 ? n1 + 1 : n1;
			d *= M;
			sendcounts[i] = d;
			displs[i] = counter;
			counter += d;
		}
	}
	MPI_Scatterv(v2.data(),
		sendcounts.data(),
		displs.data(),
		MPI_DOUBLE,
		local_v2.data() + displs[myrank],
		sendcounts[myrank],
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
	
	if (n != 1) {
		for (int p = line_displs[myrank]; p < line_displs[myrank] + line_count[myrank]; p++) {
			for (int i = 0; i < K; i++) {
				for (int j = 0; j < M; j++) {
					local_result[i * M + j] += local_v1[p * K + i] * local_v2[p * M + j];
				}
			}
		}
	}
	else {
		for (int p = myrank * n1; p < (myrank + 1) * n1; p++) {
			for (int i = 0; i < K; i++) {
				for (int j = 0; j < M; j++) {
					local_result[i * M + j] += local_v1[p * K + i] * local_v2[p * M + j];
				}
			}
		}
	}

	MPI_Gather(local_result.data(), 
		K * M, 
		MPI_DOUBLE, 
		result_component.data() + myrank * K * M, 
		K * M, 
		MPI_DOUBLE, 
		0, 
		MPI_COMM_WORLD);
	/*
	MPI_Gatherv(local_result.data(), 
		K * M, 
		MPI_DOUBLE, 
		result_component.data(),
		sendcounts.data(), 
		displs.data(), 
		MPI_DOUBLE, 
		0, 
		MPI_COMM_WORLD);
		*/
		
	if (myrank == 0) {
		for (int j = 0; j < M * K; j++) {
			for (int i = 0; i < n; i++) {
				global_result[j] += result_component[i * K * M + j];
			}
		}

		cout << "\n\n";
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < M; j++) {
				cout << global_result[i * M + j] << " ";
			}
			cout << "\n";
		}
	}

	time_work = MPI_Wtime() - time_work;
	
	if (myrank == 0) {
		cout << "\n\n" << time_work;
	}
	MPI_Finalize();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
