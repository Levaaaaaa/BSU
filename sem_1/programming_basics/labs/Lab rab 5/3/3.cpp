// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/*3. Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, 
в котором нужно собрать общие элементы двух*/

using std::cout;
using std::cin;
using std::vector;

bool isElementInArray(int n, vector<int> v);
void initVector(int size, vector<int>& v);
void printVector(vector<int> v);
vector<int> intersection(vector<int>, vector<int>);
void brush(vector<int>&, vector<int>, vector<int>);
int firstEntry(vector<int> v, int n);
int secondEntry(vector<int> v, int n);
void delElement(vector<int>&, int index);

int main()
{
    int m;
    cout << "Enter m ";
    cin >> m;
    vector<int> a(m);
    initVector(m, a);

    int n;
    cout << "Enter n ";
    cin >> n;
    vector<int> b(n);
    initVector(n, b);

    vector<int> v = intersection(a, b);
    printVector(v);

    return 0;
}

vector<int> intersection(vector<int> v1, vector<int> v2)
{
    vector<int> result(v1.size() + v2.size());
    if (v1.size() >= v2.size())
    {
        for (size_t i = 0; i < v1.size(); i++)
        {
            if (isElementInArray(v1[i], v2))
            {
                result[i] = v1[i];
            }
        }
    }
    else
    {
        for (size_t i = 0; i < v2.size(); i++)
        {
            if (isElementInArray(v2[i], v1))
            {
                result[i] = v2[i];
            }
        }
    }

    return result;
}

void brush(vector<int>& v, vector<int> v1, vector<int> v2)
{
    if (isElementInArray(0,v1)||isElementInArray(0,v2))
    {
        for (size_t i = secondEntry(v,0); i < v.size(); i++)
        {
            if (v[i] == 0)
            {
                delElement(v, i);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
            {
                delElement(v, i);
            }
        }
    }
}

void delElement(vector<int>& v, int index)
{
    if (index != (v.size() - 1))
    {
        for (size_t i = index; i < v.size(); i++)
        {
            v[i] = v[i + 1];
        }
        v.pop_back();
    }
    else
    {
        v.pop_back();
    }
}
int secondEntry(vector<int> v, int n)
{
    for (size_t i = firstEntry(v, n); i < v.size(); i++)
    {
        if (v[i] == n)
        {
            return i;
        }
    }
}

int firstEntry(vector<int> v, int n)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
        {
            return i;
        }
    }
}

bool isElementInArray(int n, vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
        {
            return true;
        }
    }

    return false;
}

void initVector(int size, vector<int>& v)
{
    int e;
    for (size_t i = 0; i < size; i++)
    {
        cin >> e;
        v.push_back(e);
    }
}

void printVector(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
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
