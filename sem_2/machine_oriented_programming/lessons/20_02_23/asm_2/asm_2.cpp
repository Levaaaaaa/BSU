#include <iostream>

int main()
{
	int arr[] =  {4,2,1,6,7,8,10,3,5,9 };
	int size1 = 10;
	int max;

	_asm
	{
		xor eax, eax
		mov ecx, size1
		sub ecx, 1
		lea esi, arr
		mov ebx, [esi+(ecx)*4]
		begin:
		mov eax, [esi + (ecx-2) * 4]
		cmp eax, ebx
		jl less
		jmp con
		less:
		mov ebx, [eax]
		jmp con
		con:
		loop begin

		mov max, ebx
	}

	std::cout << max;
	return 0;
}