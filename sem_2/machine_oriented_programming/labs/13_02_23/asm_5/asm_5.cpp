#include <iostream>

int main()
{
    int a, b, c;
    std::cout << "Enter three number \n";
    std::cin >> a >> b >> c;
    int sum = 0;

    _asm
    {
        mov eax, a
        mov ecx, a
        mov ebx, 2
        cdq
        idiv ebx
        cmp edx, 0
        jnz next1
        add sum, ecx

        next1:
        mov eax, b
        mov ecx, b
        mov ebx, 2
        cdq
        idiv ebx
        cmp edx, 0
        jnz next2
        add sum, ecx

        next2:
        mov eax, c
        mov ecx, c
        mov ebx, 2
        cdq
        idiv ebx
        cmp edx, 0
        jnz the_end
        add sum, ecx
        the_end:
    }
    std::cout << sum;

    return 0;
}