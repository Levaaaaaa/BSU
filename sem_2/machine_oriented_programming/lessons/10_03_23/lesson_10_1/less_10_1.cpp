#include <iostream>

extern "C" float* _fastcall calculateCos(int N, float* delta);

int main()
{
	float* del = nullptr;
	std::cout << *calculateCos(20, del);
	return 0;
}