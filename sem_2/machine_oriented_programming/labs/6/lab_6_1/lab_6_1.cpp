#include <iostream>

const int M = 3;
extern "C" void __fastcall CreateVectorB(int A[][M], int N, int M,	 int* B);

int main()
{
	unsigned int A[][M] = { {0,2,3},{1,2,0},{0,2,3} };
	int N = 3;
	int* B = new int[N];

	_asm 
	{
		lea ecx, A
		mov edx, N
		push B
		push M
		call CreateVectorB
		pop eax
		pop eax
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << B[i] << " ";
	}
	return 0;
}