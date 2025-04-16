#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter a and b ";
    std::cin >> a >> b;
    int stat = 0;
    int x;

    _asm
    {
        mov eax, b
        ; mov edx, b
        mov ebx, a
        mov edx, 0
        ; sub ebx, edx
        cmp ebx, 0
        jz uncorrect_input_end
        idiv ebx
        cmp edx, 0
        jnz isnt_int_result
        not eax
        add eax, 1
        mov x, eax
        jmp the_end

        uncorrect_input_end:
        mov stat, 1
        jmp the_end

        isnt_int_result:
        mov stat, 2
        jmp the_end

        the_end:
    }

    std::cout << "\n";
    switch (stat) {
    case 0: {
        std::cout << "x is " << x << "\n";
        break;
    }
    case 1:
        std::cout << "Uncorrect input" << "\n";
        break;
    case 2:
        std::cout << "Result is not integer" << "\n";
    }

    return 0;
}