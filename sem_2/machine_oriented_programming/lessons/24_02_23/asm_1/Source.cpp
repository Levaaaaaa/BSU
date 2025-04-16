#include <iostream>

//cчитаем нулевые зоны


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
        mov edx, 0;флаг

        for1:
        cmp[ebx], 0;     элемент массива сравниваем с 0
        jnz flag_zero;   если эл-т равен 0
        cmp edx, 0  ;    проверяем флаг
        jnz con_loop
        mov edx, 1;      если 0, то поменять, тк закончилась нулевая зона
        inc eax;         увеличиваем счётчик нулевых зон
        jmp con_loop
        flag_zero:
        mov edx, 0;      меняем флаг

        con_loop:
        add ebx, 4; смещение на следующий элемент
        loop for1

        mov count, eax
    }

    std::cout << count;
    return 0;
}