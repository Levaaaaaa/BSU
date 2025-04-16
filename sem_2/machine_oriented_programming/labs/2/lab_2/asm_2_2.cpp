#include <iostream>

int main()
{
	int a, b;
	std::cout << "Enter a,b\n";
	std::cin >> a >> b;
	int nod = 0;

	_asm
	{
		mov eax, a
		mov ebx, b
		mov edx, ebx

		while1:
		mov ebx, edx
		cdq
		idiv ebx
		cmp edx, 0
		jnz while1

		mov ecx, ebx

		cmp ecx, 1
		je the_end
		cmp ecx, a
		je the_end
		mov eax, a
		cdq 
		idiv ecx
		mov a, eax
		mov eax, b
		cdq
		idiv ecx
		mov b, eax

		the_end:
	}

	std::cout << "\n" << a << "/" << b << "\n";

	return 0;
}