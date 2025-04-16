#include <iostream>

int main()
{
    //(à^4-2)/(à-4)

    int a;
    std::cout << "Enter a ";
    std::cin >> a;
    int result;
    _asm
    {
        mov eax, a
        sub eax, 4

        cmp eax, 0
        jz zero
        jg greater
        jl less

        zero: 
            mov result, 0
            jmp the_end
        
        greater :
            jmp less
        less :

            mov ebx, eax
            mov eax, a
            imul eax
            imul eax
            sub eax, 2
            cdq
            idiv ebx
            mov result, eax
        jmp the_end
        the_end:
    }

    std::cout << result;
    return 0;
}