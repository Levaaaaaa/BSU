// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[])
{
	int l;
	int n = 2;
	int myrank, ranksize;
//	vector<int> result(n);
	double my_result = 0;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &ranksize);
	n = ranksize;

	if (myrank == 0) {
//		printf("Enter length of vectors ");
		//scanf_s("%ld", &l);
		l = atoi(argv[1]);
	}

	MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);
	vector<double> v1, v2;
	if (myrank == 0) {
		double num1, num2;
		for (int i = 0; i < l; i++) {
			num1 = rand() % 2 == 0 ? 0 : -1;
			v1.push_back(num1);
			num2 = rand() % 2 == 0 ? 0 : -1;
			v2.push_back(num2);
			cout << num1 << " " << num2 << "\n";
		}

	}
	MPI_Barrier(MPI_COMM_WORLD);
	int n1 = l / n;
	int n2 = l % n;
	vector<int> sendcounts(n);
	vector<int> displs(n);

	int counter = 0;
	for (int i = 0; i < n; i++) {
		int d = i < n2 ? n1 + 1 : n1;
		sendcounts[i] = d;
		displs[i] = counter;
		counter += d;
	}
	vector<double> ownV1(l), ownV2(l);
//	int LOCAL_N = myrank < n2 ? n1 + 1 : n1;
	MPI_Scatterv(v1.data(), sendcounts.data(), displs.data(), MPI_DOUBLE, ownV1.data(), l, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Scatterv(v2.data(), sendcounts.data(), displs.data(), MPI_DOUBLE, ownV2.data(), l, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//	MPI_Scatter(v1.data(), n1, MPI_INT, ownV1.data(), n1, MPI_INT, 0, MPI_COMM_WORLD);
//	MPI_Scatter(v2.data(), n1, MPI_INT, ownV2.data(), n1, MPI_INT, 0, MPI_COMM_WORLD);

	for (int i = 0; i < l; i++) {
		my_result += ownV1[i] * ownV2[i];
	}

//	MPI_Gather(&result[0], 1, MPI_INT, &my_result, 1, MPI_INT, 0, MPI_COMM_WORLD);
	double global_res = 0;
	MPI_Reduce(&my_result, &global_res, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if (myrank == 0) {
		cout << global_res;
	}
	MPI_Finalize();
	return 0;
}