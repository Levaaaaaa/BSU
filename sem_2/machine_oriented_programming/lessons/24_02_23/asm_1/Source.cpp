#include <iostream>

//c������ ������� ����


int main()
{
    int size1 = 7;
    int A[] = { 1,1,2,1,1,4,8 };
    int count = 0;

    _asm
    {
        mov ecx, size1
        mov eax, count
        lea ebx, A
        mov edx, 0;����

        for1:
        cmp[ebx], 0;     ������� ������� ���������� � 0
        jnz flag_zero;   ���� ��-� ����� 0
        cmp edx, 0  ;    ��������� ����
        jnz con_loop
        mov edx, 1;      ���� 0, �� ��������, �� ����������� ������� ����
        inc eax;         ����������� ������� ������� ���
        jmp con_loop
        flag_zero:
        mov edx, 0;      ������ ����

        con_loop:
        add ebx, 4; �������� �� ��������� �������
        loop for1

        mov count, eax
    }

    std::cout << count;
    return 0;
}