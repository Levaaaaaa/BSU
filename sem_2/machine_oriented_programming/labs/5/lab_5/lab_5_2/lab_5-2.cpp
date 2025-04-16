#include <iostream>
#include <cmath>

//кол-во совпадающих цифр после точки умноженное на 10 - кол-во итераций

extern "C" float* _fastcall my_ln2(int n);

int main()
{
	int n = 23;
	float* ptr1;
	_asm
	{
		mov ecx, n
		call my_ln2
		mov ptr1, eax
	}
	for (size_t i = 0; i < length; i++)
	{

	}
//	std::cout << *ptr1 << "\n";
	//std::cout << log(2);
	return 0;
}