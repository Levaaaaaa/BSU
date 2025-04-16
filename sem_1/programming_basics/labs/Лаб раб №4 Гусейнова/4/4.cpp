// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
/*4. Реализовать функцию для обработки массива целых чисел. 
Функция находит минимальный элемент массива 
и сортирует все элементы левее его по убыванию,
а правее его – по возрастанию. 
Функция возвращает индекс минимального элемента. */

using std::cout;
using std::cin;
using std::vector;

int indexOfMin(vector<int>);
void initVector(vector<int>&, int max, int size);
void BubbleSort(vector<int>&, int begin, int end, int mod);
void Swap(int a, int b);
int Result(vector<int>&);

int main()
{
	int size;
	cout << "Enter size ";
	cin >> size;
	vector<int> vec(size);
	initVector(vec, 1000, size);
	//printVector(vec);
	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << "\n";
	cout << "\n";
	Result(vec);

	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << "\n";
	//printVector(vec);
	return 0;
}

void initVector(vector<int>& v, int max, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		v[i] = rand() % max;
	}
}

void printVector(vector<int> v)
{
	for (int i : v)
	{
		cout << i << " ";
	}
	cout << "\n";
}

void BubbleSort(vector<int> &v, int begin, int end, int m) //m - режим сортировки (1- по возрастанию; 2 - по убыванию)
{
	for (size_t i = end; i > begin; i--) //begin - индекс начала сортировки, end - индекс конца
	{
		for (size_t j = begin; j < i; j++)
		{
			if (m == 1)
			{
				if (v[j] > v[j + 1])
				{
					Swap(v[j], v[j + 1]);
				}
			}
			else 
			{
				if (m == 2)
				{
					if (v[j] < v[j + 1])
					{
						Swap(v[j], v[j + 1]);
					}
				}
			}
		}
	}
}

void Swap(int a, int b)
{
	int p = a;
	a = b;
	b = p;
}

int indexOfMin(vector<int> v)
{
	int min = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] < v[min])
		{
			min = i;
		}
	}

	return min;
}

int Result(vector<int> &v)
{
	int indexMin = indexOfMin(v);

	BubbleSort(v, 0, indexMin, 2);
	BubbleSort(v, indexMin, 0, 1);

	return indexMin;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
