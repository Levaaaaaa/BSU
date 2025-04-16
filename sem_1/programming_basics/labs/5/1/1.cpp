// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#ifndef vector
#include <vector>

std::vector<double> sum(std::vector<double>, std::vector<double>);
void saveVector(std::vector<double>&, std::vector<double>);
std::vector<double> Add(std::vector<double>, std::vector<double>);
std::vector<int> multiply(std::vector<int>, std::vector<int>);

template <typename T>
void printVector(std::vector<T> a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << ' ';
    }
}

int main()
{
    std::vector<double> a = { 1,2,3,4,5 };
    std::vector<double> b = { 6,7,8,9,10 };

    printVector(sum(a, b));

    std::cout << "\n\n";

    
    std::vector<int> c = { 1,2,3,4,5 };
    std::vector<int> d = { 6,7,8,9,10 };

    printVector(multiply(c,d));
    
}

std::vector<int> multiply(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> result (a.size()+b.size());
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < a.size(); j++)
        {
            for (size_t k = 0;  k < b.size();  k++)
            {
                if ((j + k) == i) result[i] += a[j] * b[k];
            }

        }
        
    }

    return result;
}

std::vector<double> sum(std::vector<double> a, std::vector<double> b)
{
    int max_size = a.size() > b.size() ? a.size() : b.size();
    std::vector<double> result;

    if (a.size() >= b.size()) {
        saveVector(result, Add(a, b));
    }
    else saveVector(result, Add(b, a));

    return result;
}

void saveVector(std::vector<double>& v, std::vector<double> a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        v.push_back(a[i]);
    }
}

std::vector<double> Add(std::vector<double> big_vector, std::vector<double> small_vector)
{
    for (size_t i = 0; i < small_vector.size(); i++)
    {
        big_vector[i] += small_vector[i];
    }

    return big_vector;
}

#endif

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
