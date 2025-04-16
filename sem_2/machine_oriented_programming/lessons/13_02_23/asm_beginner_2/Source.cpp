#include<iostream>
int main()
{
    int a = 11, b = 4, x = 10, result;
    //res=(a*x*x-b*x+10)/(x-a)
    
    //в ассемблере нет логиеских операций
    _asm
    {
        //mov eax, x
        //mul eax; eax = x * x
        //imul a; eax = a * x * x
        //mov ecx, eax
        //mov eax, b
        //imul x
        //sub ecx, eax; ecx = a * x * x - b * x
        //add ecx, 10

        mov eax, ecx
        mov ebx, x
        sub ebx, a; ebx = x - a

        cmp ebx, 0
        jg greater      ;если больше
        jz zero         ;если ноль
        jl less         ;если меньше

        greater: 
            mov eax, x
            mul eax; eax = x * x
            imul a; eax = a * x * x
            mov ecx, eax
            mov eax, b
            imul x
            sub ecx, eax; ecx = a * x * x - b * x
            add ecx, 10
            mov eax, ecx

        zero: 
            mov result, 0
            jmp the_end
        less :
            mov result, -1
            jmp the_end

        cdq
        idiv ebx; eax = eax / ebx
        mov result, eax
        jmp the_end
        
        the_end:
    }
    std::cout << result << std::endl;
    //std::cout << (a * x * x - b * x + 10) / (x - a);

    return 0;
}