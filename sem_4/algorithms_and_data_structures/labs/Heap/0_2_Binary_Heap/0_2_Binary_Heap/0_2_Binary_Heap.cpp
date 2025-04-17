// 0_2_Binary_Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool isBinaryHeap(vector<long long>& v, long long n) {
    for (long long i = 1; i <= (n / 2); i++) {
        if (2 * i <= n && v[2 * i] < v[i]) {
            return false;
        }
        if (2 * i + 1 <= n && v[2 * i + 1] < v[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream in("input.txt");
    long long n;
    in >> n;
    vector<long long> v(n+1);

    for (long long i = 1; i <= n; i++) {
        in >> v[i];
    }

    in.close();

    ofstream out("output.txt");
    bool res = isBinaryHeap(v, n);
    out << (res ? "Yes" : "No");
    out.close();

    return 0;
}