#include <iostream>

int main()
{
    int x;
    std::cout << "Enter the x ";
    std::cin >> x;
    short min = 0;
    short max = 0;

    _asm
    {
        mov bl, 0
        mov edx, x
        mov eax, 1
        mov bh, 2
        while1:
        cmp edx, eax
        jl the_end
        inc ebx
        mul bh
        jmp while1
        
        the_end:
        mov byte ptr max, bl
        sub bl, 1
        mov byte ptr min, bl
    }

    std::cout << "\n" << min << " " << max << "\n";

    return 0;
}