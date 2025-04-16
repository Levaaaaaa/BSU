#include <iostream>

extern "C" int _stdcall MaxSeq(int* arr, int arr_size, int& seq_size);
int main()
{
    int arr_size = 15, seq_size = 0;
    int* arr = new int[arr_size] { 1, 2, 0, 4, 15, -4, 8, 9, 1, 1, 3, 20, 1, -2, 4 };
    std::cout << MaxSeq(arr, arr_size, seq_size);
    return 0;
}