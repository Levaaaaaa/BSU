﻿// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
using std::cout;
using std::cin;

/*5. Для заданного N найти все меньшие его числа Армстронга
(n-значное число называется числом Армстронга,
если оно равно сумме n-х степеней своих цифр,
например, 153=1^3+5^3+3^3).   */

int countNumLength(int n) 
{
    int length = 0;

    while (n!=0)
    {
        length++;
        n /= 10;
    }

    return length;
}

int power(int num, int pow) {
    int power = 1;

    for (int i = 0; i < pow; i++)
    {
        power *= num;
    }

    return power;
}

int main()
{
    int n, sum = 0, helpI;

    cout << "Enter n ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        helpI = i;
        int length = countNumLength(i);
        for (int j = 0; j < length; j++)
        {
            int number = helpI % 10;
            sum += power(number, length);
            helpI /= 10;
        }

        if (sum == i) {
            cout << i << "\n";
        }
        sum = 0;
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
