#include <iostream>

int main()
{
    int x;
    std::cout << "Enter the x ";
    std::cin >> x;
    int sum = 0, count;
    _asm
    {
        mov eax, x
        mov ecx, 0
        mov ebx, 10

        while1:
        cdq 
        idiv ebx
        add sum, edx
        inc ecx
        cmp eax, 0
        jz the_end
        jmp while1

        the_end:
        mov count, ecx

    }

    std::cout << "\n";
    std::cout << "Sum is " << sum << "\n" << "Count is " << count << "\n";
    return 0;
}