#include <iostream>

int main()
{
    int x, pow;
    std::cout << "Enter x and pow ";
    std::cin >> x >> pow;

    _asm
    {
        mov ebx, x
        mov eax, ebx
        mov ecx, pow

        for1:
        dec ecx
        cmp ecx, 0
        jz the_end
        imul ebx
        jmp for1
        /*repeat:
            imul ebx
        loop repeat*/

        the_end:
        mov x, eax
    }

    std::cout << "\n" << x << "\n";

    return 0;
}