// Шаблонная функция.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
                        // чем шаблонная функция отличается от обычной, в чём её преимущество?
                        // зачем нужны шаблонные функции
using std::cout;
using std::cin;

template<typename T> // - шаблонная функция: синтаксис 
//void Allocate(T*, size_t); - при таком прототипе функция работать не будет
void Allocate(T*&, size_t); // - при таком - будет

template<typename T> // - тоже шаблонная функция
void Diallocate(T*&);

template<typename T>
void printArray(T*, size_t);

template<typename T>
void ReadArray(T*, size_t);

int main()
{
    size_t sizeI, sizeD;
    int* ArrI = nullptr;
    double* ArrD = nullptr;

    cout << "Enter sizeI, sizeD \n";
    cin >> sizeI >> sizeD;
    cout << "\n\n";
    Allocate(ArrI, sizeI);
    cout << "\n\n";
    ReadArray(ArrI, sizeI);
    cout << "\n\n";
    printArray(ArrI, sizeI);
    Diallocate(ArrI);

    cout << "\n\n\n";

    cout << "\n\n";
    Allocate(ArrD, sizeD);
    cout << "\n\n";
    ReadArray(ArrD, sizeD);
    cout << "\n\n";
    printArray(ArrD, sizeD);
    Diallocate(ArrD);

    return 0;
}

template<typename T>
void Allocate(T*& A, size_t size)
{
    A = new T[size];
}

template<typename T>
void Diallocate(T*& A)
{
    delete A;
    A = nullptr; // nullptr - нулевой пустой указатель
}

template<typename T>
void printArray(T* A, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n\n";
}

template<typename T>
void ReadArray(T* A, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cin >> A[i];
    }
}
                                    // шаблонные функции используются когда нужны одинаковые функции для разных типов данных
                                    // чтобы не переписывать или перегружать функцию для работы с другим типом данных, можно использовать шаблонные функции

                                    
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
