// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/*1. Найти сумму и произведение двух многочленов, заданных динамическими массивами своих коэффициентов.*/

using std::cin;
using std::cout;
using std::vector;

vector<int> sumVector(vector<int>, vector<int>);
vector<int> mult(vector<int>, vector<int>);         
void preparation(vector<int>&, vector<int>&);       //подготовка: увеличение меньшего массива до длины большего
vector<int> alignment(vector<int>, vector<int>);    //выравнивание: заполнение добавление в начало меньшего массива нулей для его увеличения
void printVector(vector<int>);

int main()
{
    vector<int> v1 = { 1,2,3,4 };
    vector<int> v2 = { 5,6,7,8 };

    vector<int> sum = sumVector(v1, v2);
    vector<int> multiply = mult(v1, v2);
    printVector(sum);
    cout << "\n\n";
    printVector(multiply);
    return 0;
}

vector<int> sumVector(vector<int> v1, vector<int> v2)
{
    vector<int> result;
    
    preparation(v1, v2);    //теперь длина векторов должна быть одинаковой

    for (size_t i = 0; i < v1.size(); i++)
    {
        result.push_back(v1[i] + v2[i]);
    }

    return result;
}

vector<int> mult(vector<int> v1, vector<int> v2)
{
    vector<int> result;

    preparation(v1, v2);    //теперь длина векторов должна быть одинаковой

    for (size_t i = 0; i < v1.size(); i++)
    {
        for (size_t j = 0; j < v2.size(); j++)
        {
            result.push_back(v1[i] * v2[j]);
        }
    }

    return result;
}

void printVector(vector<int> result)
{
    for (size_t i = 0; i < result.size()-1; i++)
    {
        if (result[i] != 0)
        {
            cout << result[i] << "x^" << result.size() - (i + 1) << " + ";
        }
    }
    cout << result[result.size() - 1];
}
void preparation(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() > v2.size())
    {
        v2 = alignment(v1, v2);
    }
    else
    {
        if (v1.size() < v2.size())
        {
            v1 = alignment(v2, v1);
        }
    }
}

vector<int> alignment(vector<int> v1, vector<int> v2)
{
    vector<int> result;
    while (result.size() < (v1.size() - v2.size()))
    {
        result.push_back(0);
    }

    for (size_t i = 0; i < v2.size(); i++)
    {
        result.push_back(v2[i]);
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
