// 0_3_isSearchTree_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

std::ifstream in("bst.in");
std::ofstream out("bst.out");
long long matrix[800001][3] = { 0 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long min = std::numeric_limits<long long>::min();
	long long max = std::numeric_limits<long long>::max();

	long long count, start;
	in >> count;
	in >> start;
	matrix[0][0] = min;
	matrix[0][1] = start;
	matrix[0][2] = max;

	bool result = true;
	for (long long i = 0; i < count; i++) {
		std::string lr;
		std::string l;
		long long v, par;
		std::getline(in, l);
		std::stringstream str(l);
		str >> v >> par >> lr;

		if (lr == "L") {
			if (!(matrix[par - 1][0] <= v && v < matrix[par - 1][1])) {
				result = false;
			}
			matrix[i][0] = matrix[par - 1][0];
			matrix[i][1] = v;
			matrix[i][2] = matrix[par - 1][1];
		}
		if (lr == "R") {
			if (!(matrix[par - 1][1] <= v && v < matrix[par-1][2])) {
				result = false;
			}
			matrix[i][0] = matrix[par - 1][1];
			matrix[i][1] = v;
			matrix[i][2] = matrix[par - 1][2];
		}
	}

	out << (result ? "YES" : "NO");

	in.close();
	out.close();
	return 0;
}

