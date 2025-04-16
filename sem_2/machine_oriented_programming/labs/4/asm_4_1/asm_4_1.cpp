#include <iostream>
#include <algorithm>

extern "C" int _stdcall swapMax(int* arr, int arr_size);

int main()
{
	int arr_size = 7;
	int* arr = new int[arr_size]{ 14,7,2,-9,6,12,-3 };
	int a = swapMax(arr, arr_size);
	std::copy(arr, arr + arr_size, std::ostream_iterator<int>(std::cout, " "));

	return 0;
}