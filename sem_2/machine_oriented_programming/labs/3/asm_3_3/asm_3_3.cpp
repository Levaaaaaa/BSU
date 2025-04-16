#include <iostream>

int main()
{
    int arr[] = { 1,-2,3,-4,5,6,7,-8,9,10,-11,12,13,-14,15 };

    int result;
    _asm
    {
        lea ebx, arr
        mov edx, 15;индекс минимального
        mov eax, [ebx]
        mov ecx, 15

        loop_:
            cmp eax, [ebx]
            jg great
            jmp con
            great:
                mov eax, [ebx]
                mov edx, ecx
            con:
                add ebx, 4
        loop loop_

        mov ecx, 15
        sub ecx, edx
        ;теперь ecx - индекс мин.

        lea ebx, arr
        mov eax, [ebx]
        mov edx, [ebx+ecx*4]
        mov [ebx], edx
        mov [ebx+ecx*4], eax
    }

    std::cout << arr[0];//result;
    return 0;
}