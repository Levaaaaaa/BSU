#include <vector>
#include <iostream>
#include "ptrFun.h"
#include <fstream>

void findElem(const std::vector<int>& v, bool(*crit)(int))
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (crit(v[i])) std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

void readFile(const std::string& fileName, std::vector<int>& v)
{
    std::ifstream fin("Text.txt");
    if (!fin.is_open()) { std::cout << "Error file open\n" << std::endl;}
    while (!fin.eof())
    {
        int num;
        fin >> num;
        v.push_back(num);
    }
}
bool isEven(int num)
{
    return num % 2 == 0;
}
bool isOdd(int num)
{
    return num % 2 != 0;
}
bool isNeg(int num)
{
    return num < 0;
}