// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

std::vector<int> Conjunct(std::vector<int> a, std::vector<int> b);
bool isElement(std::vector<int> v, int a);
std::vector<int> crateRandVector(int size);
template <typename T>
void printVector(std::vector<T> a)
{
	if (a.size() == 0) std::cout << " ----- ";
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << "\n\n";
}


int main()
{
	int m, n;

	std::cin >> m >> n;
	std::vector<int> a = crateRandVector(m);
	std::vector<int> b = crateRandVector(n);

	printVector(a);
	printVector(b);

	printVector(Conjunct(a, b));
}

std::vector<int> Conjunct(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> result;
	for (size_t i = 0; i < b.size(); i++)
	{
		if (isElement(a, b[i])) result.push_back(b[i]);
	}

	return result;
}

bool isElement(std::vector<int> v, int a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (a == v[i]) return true;
	}
	return false;
}

std::vector<int> crateRandVector(int size)
{
	std::vector<int> result(size);
	for (size_t i = 0; i < size; i++)
	{
		result[i] = rand() % 1000;
	}
	return result;
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
