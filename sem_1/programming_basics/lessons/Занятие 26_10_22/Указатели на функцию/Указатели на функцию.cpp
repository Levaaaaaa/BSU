// Указатели на функцию.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
                            //ВНИМАНИЕ: ПРОТОТИПЫ РАСПОЛАГАТЬ В ПОСЛЕДНОВАТЕЛЬНОСТИ ВЫЗОВОВ (СНАЧАЛА ВНУТРЕННИЕ ФУНКЦИИ, ЗАТЕМ ВНЕШНИЕ)
                            //Основное: 
                                //указатели на функции позволяют группировать однотипные функции в массивы и создават пользовательские меню
                                //существует 3 способа объявления указателей:
                                    //std::function в библиотеке <functional>
                                    //bool (*ptrFun)(int) (к примеру)
                                    //через typedef bool (*ptrFunType)(int) - псевдоним типа

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <fstream>

using std::vector;

typedef bool (*ptrFunType)(int);    //псевдоним для типа

bool isEven(int);
bool isOdd(int);
bool isNeg(int);
std::function<bool(int)> MakeChoice();
void findElement(const vector<int>&v , std::function<bool(int)>);


int main()
{
    setlocale(0, "");
    //указатель на функцию
    //тип (*имя_указателя)(параметры)

    /*bool (*ptrFun)(int) = isEven;   //объявление указателя на функцию
                                    //можно писать "= &isEven;"
    std::cout << ptrFun(3) << "\n\n";

    std::function<bool(int)> ptrFun1 = isEven;      //объявление указателя на функцию через оболочку std::function
                                                    //через std::function. Идентично записи bool (*ptrFun)(int) = isEven;
                                                    //для std::function необходимо подключить #include <functional>
    std::cout << ptrFun1(3);

    ptrFunType ptrFun2 = isEven;    //объявление указателя на функцию с помощью псевдонима типа


                //промежуточные итоги: 
                //существует 3 способа объявления указателей на функции
                //указатель на функцию хранит адрес на первый байт функции
        
    */
                            //ЗАЧЕМ НУЖНЫ УКАЗАТЕЛИ НА ФУНКЦИИ?
    vector<int> v;
    std::ifstream fin ("text.txt");
    
    if (!fin.is_open()) { 
        std::cout << "Error file open" << std::endl; 
        return 1; 
    }

    while (!fin.eof())
    {
        int n;
        fin >> n;
        v.push_back(n);
    }
    
    findElement(v, isEven);
    findElement(v, isOdd);
    findElement(v, isNeg);

    
                //КАК РЕАЛИЗАТЬ ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ?
    findElement(v, MakeChoice());

    
    return 0;
}

std::function<bool(int)> MakeChoice()   //функция возвращает нужный указатель
{
    int choice;
    std::function<bool(int)> arrayFun[] = { isEven, isOdd, isNeg }; //можно объявить так: bool (*arrFun[])(int) = {isEven, isOdd, isNeg};
    std::cout << "Введите:\n 1. Четные\n2. Нечётные\n3. Отрицательные \n";
    std::cin >> choice;

    return arrayFun[choice - 1];
}

void findElement(const vector<int>& v, std::function<bool(int)> crit)    //функция ищет в векторе элементы по критерию crit
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (crit(v[i]))
        {
            std::cout << v[i] << " ";
        }
    }
}

bool isEven(int num)
{
    return num % 2 == 0;
}

bool isOdd(int num)
{
    return num % 2 == 1;
}

bool isNeg(int num)
{
    return num < 0;
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
