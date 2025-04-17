#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

const int N = 5;
//const int M = 5;
vector<vector<double>> a;
vector<double> b;
stack<pair<int, int>> columns; //храним пары перенумерованных столбцов в порядке их перенумерации
double det_a;
int row_column_change_count = 0;

vector<vector<double>> multiply_matrix(vector<vector<double>> a1, vector<vector<double>> a2);
void swap_rows(vector<vector<double>>& a, vector<double>& b, int row1, int row2);
void swap_columns(vector<vector<double>>& a, int column1, int column2);
void find_main_item(vector<vector<double>>& a, vector<double>& b, int k);
void restore_x(vector<double>& x);
vector<double> calculate(vector<vector<double>> a, vector<double> b);
void input(vector<vector<double>>& a, vector<double>& b);
vector<double> calculate_error(vector<vector<double>> a, vector<double> x, vector<double> b);
double calculate_norm(vector<vector<double>> a);
void output(vector<double> error, string filename);
void output_matrix(vector<vector<double>> out);

int main()
{

	a = vector<vector<double>>(N, vector<double>(N));
	b = vector<double>(N);

	input(a, b);
	vector<double> x = calculate(a, b);
	vector<double> error = calculate_error(a, x, b);
	output(error, "out.txt");
	output(x, "x_out.txt");
	//calculate A^(-1)
	input(a, b);
	vector<vector<double>> E = vector<vector<double>>(N, vector<double>(N, 0));
	for (int i = 0; i < N; i++) {
		E[i][i] = 1;
	}

	vector<vector<double>> r_A = vector<vector<double>>(N, vector<double>(N, 0));
	for (int i = 0; i < N; i++) {
		r_A[i] = calculate(a, E[i]);
	}

	//transpon A^(-1)
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			swap(r_A[i][j], r_A[j][i]);
		}
	}

	vector<vector<double>> R = vector<vector<double>>(N, vector<double>(N, 0));
	vector<vector<double>> mult = multiply_matrix(a, r_A);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			R[i][j] = E[i][j] - mult[i][j];
		}
	}

	output_matrix(R);

	double condition_number = calculate_norm(a) * calculate_norm(r_A);
	ofstream fout("con_num.txt");
	fout << condition_number;
	fout.close();
	return 0;
}

//первоначально без выбора главного элемента
//нужно добавить выбор по строке и столбцу
vector<double> calculate(vector<vector<double>> a, vector<double> b) {
	//прямой ход
	for (int k = 0; k < N; k++) {
		find_main_item(a, b, k);
		for (int i = k + 1; i < N; i++) {
			for (int j = k + 1; j < N; j++) {
				a[i][j] -= a[i][k] * a[k][j] / a[k][k];
			}
			b[i] -= b[k] * a[i][k] / a[k][k];
		}
	}

	//calculate determinant A
	det_a = row_column_change_count % 2 == 0 ? 1 : -1;
	for (int i = 0; i < N; i++) {
		det_a *= a[i][i];
	}

	vector<double> x = vector<double>(N);

	x[N - 1] = b[N - 1] / a[N - 1][N - 1];

	for (int i = N - 2; i >= 0; i--) {
		x[i] = b[i];
		for (int j = i + 1; j < N; j++) {
			x[i] -= a[i][j] * x[j];
		}
		x[i] /= a[i][i];
	}

	restore_x(x);

	return x;
}

void find_main_item(vector<vector<double>>& a, vector<double>& b, int k) {
	/*
		нужно найти максимальный элемент правого нижнего минора [n-k][n-k] матрицы A
		и путем обмена местами строк и столбцов переставить его на позицию A[k][k]
		при обмене местами двух столбцов следует сохранять номера столбцов в стек columns
		при обмене местами двух строк следует менять местами соответствующие строки и в столбце b
	*/

	double max = a[k][k];
	int max_column = k, max_row = k;

	//find max in minor
	for (int row = k; row < N; row++) {
		for (int column = k; column < N; column++) {
			if (a[row][column] > max) {
				max = a[row][column];
				max_column = column;
				max_row = row;
			}
		}
	}

	/*
		если максимум минора находится в k-ой строке, то не нужно менять местами строки
		если максимум минора находится в k-м столбце, то не нужно менять местами столбцы
		иначе следует менять местами и строки, и столбцы
	*/

	if (max_column != k) {
		swap_columns(a, k, max_column);
	}
	if (max_row != k) {
		swap_rows(a, b, k, max_row);
	}
}

void restore_x(vector<double>& x) {
	while (!columns.empty()) {
		int source = columns.top().first;
		int target = columns.top().second;
		columns.pop();
		swap(x[source], x[target]);
	}
}
void swap_rows(vector<vector<double>>& a, vector<double>& b, int row1, int row2) {
	swap(a[row1], a[row2]);
	swap(b[row1], b[row2]);
	row_column_change_count++;
}
void swap_columns(vector<vector<double>>& a, int column1, int column2) {
	for (int i = 0; i < N; i++) {
		swap(a[i][column1], a[i][column2]);
	}
	columns.push(pair<int, int>(column1, column2));
	row_column_change_count++;
}
vector<double> calculate_error(vector<vector<double>> a, vector<double> x, vector<double> b) {
	vector<double> pred_result = vector<double>(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pred_result[i] += a[i][j] * x[j];
		}
	}

	vector<double> error = vector<double>(N);
	for (int i = 0; i < N; i++) {
		error[i] = b[i] - pred_result[i];
	}

	return error;
}

vector<vector<double>> multiply_matrix(vector<vector<double>> a1, vector<vector<double>> a2) {
	vector<vector<double>> result = vector<vector<double>>(a1.size(), vector<double>(a2[0].size()));
	for (int row1 = 0; row1 < a1.size(); row1++) {
		for (int column2 = 0; column2 < a2[0].size(); column2++) {
			for (int item = 0; item < a2[0].size(); item++) {
				result[row1][column2] += a1[row1][item] * a2[item][column2];
			}
		}
	}

	return result;
}

void input(vector<vector<double>>& a, vector<double>& b) {
	ifstream fin_a ("A.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin_a >> a[i][j];
		}
	}

	ifstream fin_b("B.txt");

	for (int i = 0; i < N; i++) {
		fin_b >> b[i];
	}
}

void output(vector<double> error, string filename) {
	ofstream fout(filename);
	for (double d : error) {
		fout << d << "\n";
	}
	fout.close();
}

void output_matrix(vector<vector<double>> out) {
	ofstream fout("out_R.txt");
	for (vector<double> v : out) {
		for (double d : v) {
			fout << d << " ";
		}
		fout << "\n";
	}

	fout << calculate_norm(out);

	fout.close();
}

double calculate_norm(vector<vector<double>> a) {
	double result = 0;
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum = 0;
		for (int j = 0; j < a[i].size(); j++) {
			sum += abs(a[i][j]);
		}
		result = max(result, sum);
	}

	return result;
}