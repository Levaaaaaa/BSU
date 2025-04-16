#include <iostream> 
extern "C" int _cdecl power(int x, int n);
int main()
{
    int a, n;
    std::cout << "Enter x and n: ";
    std::cin >> a >> n;
    std::cout << "x^n = " << power(a, n) << std::endl;

    return 0;
}