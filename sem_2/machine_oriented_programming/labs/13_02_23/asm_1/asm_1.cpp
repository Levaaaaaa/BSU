#include <iostream>

int main()
{
	int a;
	std::cout << "Enter a ";
	std::cin >> a;

	//�^5+�^3+�

	_asm
	{
		mov eax, a
		mul eax
		mul eax
		imul eax, a

		mov ebx, eax
		mov eax, a
		mul eax
		imul a

		add eax, ebx
		add eax, a
		mov a, eax
	}
	std::cout << "\n" << a;

	return 0;
}