#include <iostream>

extern "C" int _stdcall GCD(int *arr);

int main()
{
	int a = 8;
	int b = 4;
	int arr[2] = { a,b };
	GCD(arr);
	std::cout << a << "/" << b;

	return 0;
}