#include "DinamicArrayFun.h"

                           

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