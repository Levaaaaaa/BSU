#include <iostream>

int main()
{
    int a = -2, b = 4, x = 10, result;

    //result =  (a*x*x-b*x+10)/(x-a);

    _asm 
    {
        mov eax, x
        mul eax         ; eax = x * x
        imul a          ; eax = a * x * x
        mov ecx, eax
        mov eax, b
        imul x
        sub ecx, eax    ;ecx = a*x*x - b*x
        add ecx, 10

        mov eax, ecx
        mov ebx, x
        sub ebx, a      ;ebx = x-a
        cdq             ;расширение двойного слова на случай непредвиденного отрицательного числа
        idiv ebx        ;eax = eax/ebx

        mov result, eax
    }

    std::cout << result << "\n";
    std::cout << (a * x * x - b * x + 10) / (x - a);

    return 0;
}