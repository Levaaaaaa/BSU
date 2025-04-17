//метод квадратного корня

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int N = 5;

vector<double> multiply_vector(vector<vector<double>> a, vector<double> b);
vector<vector<double>> multiply_matrix(vector<vector<double>> a1, vector<vector<double>> a2);
vector<vector<double>> transponse(vector<vector<double>> a);
void input_A(vector<vector<double>>&a);
void input_b(vector<double>& b);

int main()
{
	vector<vector<double>> a = vector<vector<double>>(N, vector<double>(N));
	input_A(a);

	vector<double> b = vector<double>(N);
	input_b(b);

	vector<vector<double>> a_t = transponse(a);
	vector<vector<double>> a_sim = multiply_matrix(transponse(a), a);

	int k = 0;
	return 0;
}

vector<vector<double>> multiply_matrix(vector<vector<double>> a1, vector<vector<double>> a2) {
	vector<vector<double>> result = vector<vector<double>>(a1.size(), vector<double>(a2[0].size(), 0));
	int n = a1.size();
	int m = a2.size();
	int k = a1[0].size();
	for (int row = 0; row < n; row++) {
		for (int column = 0; column < k; column++) {
			for (int item = 0; item < m; item++) {
				result[row][column] += a1[row][item] * a2[item][column];
 			}
		}
	}

	return result;
}

vector<double> multiply_vector(vector<vector<double>> a, vector<double> b) {
	int n = a.size();
	int m = a[0].size();
	vector<double> result = vector<double>(n, 0);

	for (int row = 0; row < n; row++) {
		for (int item = 0; item < m; item++) {
			result[row] += a[row][item] * b[item];
		}
	}

	return result;
}

vector<vector<double>> transponse(vector<vector<double>> a) {
	vector<vector<double>> result = vector<vector<double>>(a.size(), vector<double>(a[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			result[i][j] = a[j][i];
		}
	}

	return result;
}
void input_A(vector<vector<double>>&a) {
	ifstream fin("../A.txt");

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

void input_b(vector<double>& b) {
	ifstream fin("../B.txt");

	for (int i = 0; i < b.size(); i++) {
		fin >> b[i];
	}

	fin.close();
}
