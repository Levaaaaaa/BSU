// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/*2. Из последовательности целых чисел выбрать три числа, 
произведение которых максимально. */

using std::cout;
using std::cin;
using std::vector;

//int maxIndexOfVector(vector<int>);

void BubbleSort(vector<int>&);

void initVector(std::vector<int>&, int);

int main()
{
    int size;

    cout << "Enter size ";
    cin >> size;

    vector<int> vec(size);

    cout << "Enter elements of vector\n";
    for (size_t i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
    
    BubbleSort(vec);

    cout << "Result: " << vec[0] << " " << vec[1] << " " << vec[2];
    return 0;
}

void BubbleSort(vector<int> &v)
{
    for (size_t i = v.size()-1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (v[j] < v[j + 1])
            {
                int p = v[j];
                v[j] = v[j + 1];
                v[j + 1] = p;
            }
        }
    }
}

/*void initVector(std::vector<int>& v, int range)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        //v[i] = rand() % range;
        std::cin >> v[i];
    }
}
/*int maxIndexOfVector(vector<int> v)
{
    int max = 0;

    for (int i = 0; i<v.size(); i++)
    {
        if (v[i] > v[max])
        {
            max = i;
        }
    }

    return max;
}*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
