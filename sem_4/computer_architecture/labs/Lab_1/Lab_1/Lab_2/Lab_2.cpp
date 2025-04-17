// Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	const int L = 3, M = 3;
	int n;		//count of threads
	int myrank;

	vector<double> source1(L * M), source2(L * M), local_source1(L * M), local_source2(L*M);
	vector<double> global_result(L * M);
	vector<double> local_result(L * M);
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &n);

	//generate matrix
	if (myrank == 0) {
		double num;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < M; j++) {
				num = rand() % 10;
				source1[i * M + j] = num;
				cout << num << " ";
				num = rand() % 10;
				source2[i * M + j] = num;
			}
			cout << "\n";
		}

		cout << "\n\n";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < M; j++) {
				cout << source2[i * M + j] << " ";
			}
			cout << "\n";
		}
	}
	int n1 = (L * M)/ n;		//целая часть
	int n2 = (L * M) % n;		//остаток

	vector<int> sendcounts(n);
	vector<int> displs(n);

	int counter = 0;
	for (int i = 0; i < n; i++) {
		int d = i < n2 ? n1 + 1 : n1;	//кол-во эл-тов для одного потока
		sendcounts[i] = d;
		displs[i] = counter;
		counter += d;
	}

	MPI_Scatterv(source1.data(),
		sendcounts.data(),
		displs.data(),
		MPI_DOUBLE,
		local_source1.data(),
		L * M,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);

	MPI_Scatterv(source2.data(),
		sendcounts.data(),
		displs.data(),
		MPI_DOUBLE,
		local_source2.data(),
		L * M,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
	/*
	//let L mod N == 0;
	int lines_per_process = L / n;
	MPI_Scatter(
		source1.data(), 
		lines_per_process * M, 
		MPI_DOUBLE, 
		local_source1.data(), 
		lines_per_process * M, 
		MPI_DOUBLE, 
		0, 
		MPI_COMM_WORLD);

	MPI_Scatter(
		source2.data(),
		lines_per_process * M,
		MPI_DOUBLE,
		local_source2.data(),
		lines_per_process * M,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
		*/
	for (int i = 0; i < L * M; i++) {
		local_result[i] = local_source1[i] - local_source2[i];
	}

	MPI_Gatherv(local_result.data(),
		n1,
		MPI_DOUBLE,
		global_result.data(),
		sendcounts.data(),
		displs.data(),
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
	/*
	MPI_Gather(
		local_result.data(),
		lines_per_process * M,
		MPI_DOUBLE,
		global_result.data() + lines_per_process * myrank,
		lines_per_process * M,
		MPI_DOUBLE,
		0,
		MPI_COMM_WORLD);
		*/
	if (myrank == 0) {
		cout << "\n\n";
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < M; j++) {
				cout << global_result[i * M + j] << " ";
			}
			cout << "\n";
		}
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
