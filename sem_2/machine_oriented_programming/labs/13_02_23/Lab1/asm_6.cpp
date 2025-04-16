#include <iostream>
#include <string>

int main()
{
    int year;
    std::cout << "Enter the year ";
    std::cin >> year;

    bool is_bissextile = 0;
    _asm {
        mov eax, year	; проверить, делится ли на 4
        mov ebx, eax
        mov ecx, 4
        cdq
        div ecx
        cmp edx, 0
        jz div4
        jmp the_end
        
        div4:           ; проверить, делитcя ли на 100
        mov ecx, 100
        mov eax, ebx
        cdq
        div ecx
        cmp edx, 0
        jz div100
        not is_bissextile
        jmp the_end

        div100:        ; если да, то проверить, делится ли на 4
        mov ecx, 400
        mov eax, ebx
        cdq
        div ecx
        cmp edx, 0
        jnz the_end
        not is_bissextile

        the_end:
    }

    std::string result = is_bissextile ? "This year is bissextile" : "This year is not bissextile";
    std::cout << "\n" << result << "\n";


    return 0;
}