#include <iostream>

int main()
{
	int x;
	std::cout << "Enter seconds ";
	std::cin >> x;
	std::cout << "\n";
	int sec, min, hours = 0;

	_asm {
		mov eax, x
		mov ebx, 60
		mov edx, 0
		cdq
		div ebx
		mov sec, edx
		cdq
		div ebx
		mov min, edx
		mov hours, eax
	}

	std::cout << "This is " << hours << "h " << min << "m " << sec << "s\n";

	return 0;
}