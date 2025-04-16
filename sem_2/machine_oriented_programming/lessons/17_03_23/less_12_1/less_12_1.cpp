#include <iostream>

const int M = 3;
const int N = 3;
extern "C" void __cdecl CreateVectorB(int A[][M], int N, int M, int* B);

int main()
{
	int A[N][M] = {			{1,2,3},
							{-5,-4,-3}, 
							{4,7,8} };

	int* B = new int[N] {0};

	_asm {
		push B
		push M
		push N 
		lea eax, A
		push eax

		call CreateVectorB

		pop eax
		pop eax
		pop eax
		pop eax
	}
	
	for (size_t i = 0; i < N; i++)
	{
		std::cout << B[i] << " ";
	}

	delete[] B;
	return 0;
}