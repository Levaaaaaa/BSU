#include <iostream>

//����� ������������ ��-� ����� ������ ��������
//p.s.: 0 ������ �� ������ ������

int main()
{
    int arr[] = { 3,9,1,7,2,0,5,10,17,25 };
    int max = 0;
    _asm
    {
        lea ebx, arr
        mov eax, [ebx]; ������������ �������
        ; mov edx, 0; ������
        mov ecx, 5

        repeat:
            cmp eax, [ebx]
            jl less
            jmp  con
            less :
                mov eax, [ebx]

            con:
                add ebx, 8
        loop repeat

        mov max, eax
    }

    std::cout << max << "\n";
    return 0;
}