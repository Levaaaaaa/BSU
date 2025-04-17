
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int multiplyMatrix(vector<int> sequence) {
	int size = sequence.size();
	vector<vector<int>> matrix(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}

	int j;
	int cost;
	for (int l = 2; l < size; l++) {
		for (int i = 1; i < size - l + 1; i++) {
			j = i + l - 1;
			matrix[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				cost = matrix[i][k] + matrix[k + 1][j] + sequence[i - 1] * sequence[k] * sequence[j];
				if (matrix[i][j] > cost) {
					matrix[i][j] = cost;
				}
			}
		}
	}

	return matrix[1][size - 1];
}


int main()
{
	ifstream in("input.txt");
	int n;
	in >> n;
	std::vector<int> matrix(n+1);

	int empty;
	for (int i = 0; i < n; i++) {
		in >> matrix[i] >> empty;
	}
	in.close();
	matrix[matrix.size() - 1] = empty;
	
	int index;
	int result = multiplyMatrix(matrix);//res(0, 0, matrix);

	ofstream out("output.txt");
	out << result;
	out.close();

	return 0;
}