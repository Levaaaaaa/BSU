// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
                        //НЕ СДЕЛАНО
using std::cin;
using std::cout;
using std::vector;

bool isElementInArray(int n, vector<int> v);
void initVector(int size, vector<int> &v);
vector<int> Conjuction(vector<int> a, vector<int> b);
void printVector(vector<int> v);

int main()
{
    cout << "Enter m ";
    int m;
    cin >> m;
    vector<int> a(m);
    initVector(m, a);

    cout << "Enter n ";
    int n;
    cin >> n;
    vector<int> b(n);
    initVector(n, b);

    vector<int> result = Conjuction(a, b);
    printVector(result);

    return 0;
}

vector<int> Conjuction(vector<int> a, vector<int> b)
{
    vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); i++)
    {
        if(!isElementInArray(a[i], result))
        {
            result[i] = a[i];
        }
    }
    
    int size = result.size();
    

    for (size_t i = 0; i < b.size(); i++)
    {
        if (!isElementInArray(b[i], result))
        {
            result.push_back(b[i]);
        }
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] == 0)
        {
            ;
        }
    }

    return result;
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
