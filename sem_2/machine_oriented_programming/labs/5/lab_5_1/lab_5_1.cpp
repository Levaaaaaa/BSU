#include <iostream>
#include <cmath>

//���-�� ����������� ���� ����� ����� ���������� �� 10 - ���-�� ��������

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