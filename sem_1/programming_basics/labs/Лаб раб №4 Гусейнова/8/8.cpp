﻿// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/*8. Написать программу, которая содержит функцию,
принимающую в качестве аргумента,
два массива (А и В) и размеры массивов.
Функция проверяет, является ли массив В подмножеством (подстрокой) массива А
и возвращает указатель на начало найденного фрагмента,
если элемента нет, возвращает 0.*/

using std::cout;
using std::cin;
using std::vector;

int isSubset(vector<int> v1, int suze1, vector<int> v2, int size2);
int IndexCoincidence(vector<int> v1, vector<int> v2);

int main()
{

}

int isSubset(vector<int> v1, int size1, vector<int> v2, int size2)
{
    bool isSub = true;
    int IndexCoin = IndexCoincidence(v1, v2);
    for (size_t i = 0; i < size2; i++)
    {
        
    }
}

int IndexCoincidence(vector<int> v1, vector<int> v2)
{
    for (size_t i = 0; i < v2.size(); i++)
    {
        if (v1[i] == v2[i]) {
            return i;
        }
    }
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
