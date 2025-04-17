// 0_3_Binomial_Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream in("input.txt", ios::in | ios::binary);
    ofstream out("output.txt");

    __int64 num;
    in >> num;
    int counter = 0;
    while (num) {
        if (num & 1) {
            out << counter << "\n";
        }
        counter++;
        num >>= 1;
    }
    in.close();
    out.close();
    return 0;
}
