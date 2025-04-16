#include <iostream>

int main()
{
    int arr[] = { 1,-2,-3,4,5,6,-7,8,9,10,-11,12,13,-14,15 };
    int result;
    _asm
    {
        lea ebx, arr
        mov ecx, 15
        mov eax, 0; cумма положительных
        mov edx, 0; счётчик положительных
        repeat:
        cmp [ebx], 0
            jg pol ;положительные
            jmp con
            pol:
                add eax, [ebx]
                inc edx
            con:
                add ebx, 4
        loop repeat
        mov ecx, edx
        cdq
        idiv ecx
        mov result, eax
    }
    
    std::cout << result;
    return 0;
}