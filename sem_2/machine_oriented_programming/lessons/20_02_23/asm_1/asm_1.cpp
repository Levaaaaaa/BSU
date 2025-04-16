#include <iostream>

//найти кол-во значащих разрядов целого числа

int main()
{
    int n;
    std::cout << "Enter n ";
    std::cin >> n;
    int result = 0;
    _asm
    {
        mov eax, n
        mov ecx, 32

        begin:
        jc end
        shl eax, 1
        loop begin

            end:
        add ecx, 1
            mov result, ecx
    }

    std::cout << result;
    return 0;
}