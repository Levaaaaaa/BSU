#include <iostream>

extern "C" void _stdcall ChangeRawCalm(int* a, int size1, int index);

//двумерные массивы

int main()
{
    int size1, index;
    std::cout << "Enter matrix size\n";
    std::cin >> size1;
    std::cout << "Enter index\n";
    std::cin >> index;
    std::cout << "\n";

    int* a = new int[size1 * size1];
    for (size_t i = 0; i < size1 * size1; i++)
    {
        std::cin >> a[i];
    }
    
    _asm {
        push index
        push size1
        push a
        call ChangeRawCalm
    }
    
    std::cout << "\n";

    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size1; j++) {
            std::cout << a[i*size1+j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}