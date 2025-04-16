#include <iostream>

int main()
{
	int x;
	std::cout << "Enter x ";
	std::cin >> x;
	int result;
	int stat = 0;	
	//stat==0 - всё в порядке
	//stat==1 - число однозначное

	_asm {
		mov eax, x
		
		mov ebx, 10
		idiv ebx	;теперь в dl хранится остаток
		
		cmp eax, 0
		mov result, edx
		jz the_end1

		mov ebx,eax

		my_while:
		cmp ebx, 0	;в eax, ebx хранится оставшийся x
		jz the_end	;в ecx хранится будущий result
		
		mov eax, dl
		mov dh, 10
		imul dh
		mov ecx, 	;сохраним соответствующий разряд, умн. на 10
		mov eax, ebx	;возвращаем оставшийся x в eax
		idiv 10 
		add ecx, eax
		jmp my_while

		the_end1:
		mov stat, 1
		the_end:
		mov result, ecx
	}

	std::cout << result;
	return 0;
}