#include <iostream>

extern "C" float* _stdcall integrate(int n);

int main()
{
	int n = 20;
	std::cout << *integrate(n);

	return 0;
}