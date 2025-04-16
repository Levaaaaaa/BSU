// 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>

//Задача 5
void initVector(std::vector<int>&, int);
void printVector(std::vector<int>);
void BubbleSort(std::vector<int>&);
int gcd(int, int);
void createArifmSeq(std::vector<int>&);
int main()
{
    size_t size;
    std::cout << "Enter vector size\n";
    std::cin >> size;
    std::vector<int> vecI(size);
    initVector(vecI, 21);
    printVector(vecI);
    BubbleSort(vecI);
    printVector(vecI);
    createArifmSeq(vecI);
    printVector(vecI);
    return 0;
}
void initVector(std::vector<int>& v, int range)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        //v[i] = rand() % range;
        std::cin >> v[i];
    }
}
void printVector(std::vector<int> v)
{
    for (size_t i = 0; i < size(v); i++)
    {
        std::cout << v[i] << "\t";
    }
    std::cout << "\n";
}
void BubbleSort(std::vector<int>& v)
{
    for (int i = size(v) - 1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
        }
    }
}
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else
            b -= a;
    }
    return a;
}
void createArifmSeq(std::vector<int>& v)
{
    std::vector<int> dif;//храним разности между элементами
    int minGCD = 1, GCD;
    for (size_t i = 0; i < size(v) - 1; i++)
    {
        dif.push_back(v[i + 1] - v[i]);
        //находим минимальный НОД
        if (i == 0)
        {
            minGCD = dif[i];
            continue;
        }
        GCD = gcd(minGCD, dif[i]);
        if (GCD < minGCD) minGCD = GCD;

    }
    std::cout << minGCD << "\n";
    int i = 0;
    int back = v.back();
    //пока элементы меньше максимального
    //элемента в последовательности
    //вставляем, если нужно элемент+минимальный НОД
    while (v[i] < back)
    {
        if (v[i + 1] == v[i] + minGCD) i++;
        else
        {
            v.insert(v.begin() + i + 1, v[i] + minGCD);
            i++;
        }
        std::cout << v[i] << "\t";
    }
    std::cout << "\n";
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
