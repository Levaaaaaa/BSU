#include <iostream>
#include <string>

extern "C" int _stdcall sumNum(int num, int *countEven, int *isSimm);
//extern "C" int _stdcall countEvenDigit(int num);
//extern "C" int _stdcall isSymmetry(int num);

//Найти сумму цифр целого числа. Подсчитать количество четных цифр. Определить, является ли число симметричным.  

int main()
{
    int x = 45;
    int countEven = 0;
    int isSimm;
    int result = sumNum(x, &countEven, &isSimm);
    std::string result2 = isSimm != 0 ? "yes" : "no";
    std::cout << "Summ of digit is " << result << "\n" << countEven << "\nIs this number simmetry: " << result2;
    //std::cout << "Count of even digits is " << countEvenDigit(x) << "\n";
    return 0;
}