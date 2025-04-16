// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
    int main() {
        enum { jan = 1, feb, mar, apr, may, june, july, aug, sep, oct, nov, dec };
        int day, month, year, daysInPreviousMonth = 0;
        std::cout << "Enter the date\n";
        std::cin >> day >> month >> year;
        switch (month)
        {
        case mar:
            (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ?
                daysInPreviousMonth = 29 : daysInPreviousMonth = 28; break;
        case may :case july: case aug: case oct:
            daysInPreviousMonth = 30; break;
        default:
            daysInPreviousMonth = 31; break;
        }
        if (day != 1) day--;
        else if (day == 1 && month != 1) {
            month--;
            day = daysInPreviousMonth;
        }
        else if (day==1 && month==1) {
            day = 31;
            month = 12;
            year--;
        }
        std::cout << day << " " << month << " " << year;
        return 0;
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
