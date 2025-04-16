// Двумерные массивы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
void initMatrix(vector<vector<int>>& A, size_t rowA, size_t colA, int range);

int main()
{
	size_t rowA = 3;
	size_t colA = 4;

    vector<vector<int>> A(rowA, vector<int>(colA));     //вектор 10х10 элементов

	size_t rowB = 4;
	size_t colB = 2;

	vector<vector<int>> B(rowB, vector<int>(colB));

	size_t rowC = 3;
	size_t colC = 2;

	vector<vector<int>> C(rowC, vector<int>(colC));

	initMatrix(A, rowA, colA, 20);
	initMatrix(B, rowB, colB, 20);
	initMatrix(C, rowC, colC, 1);



    return 0;
}

void initMatrix(vector<vector<int>>& A, size_t rowA, size_t colA, int range)
{
	for (size_t i = 0; i < rowA; i++)
	{
		for (size_t j = 0; j < colA; j++)
		{
			v[i][j] = rand() % range;
			cout << v[i][j] << " ";
		}
		cout << "\n\n";
	}
}

void multipliation //написать умножение матриц, тройной цикл с накоплением умножения и сложения

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
