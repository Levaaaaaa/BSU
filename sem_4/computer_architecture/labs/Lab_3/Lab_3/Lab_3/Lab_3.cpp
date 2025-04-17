// Lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

vector<long long> remove(vector<long long>& s, long long i) {
    swap(s[i], s[s.size() - 1]);
    s.pop_back();
    return s;
}

vector<long long> init(long long length) {
    vector<long long> result = vector<long long>(length);
    vector<long long> unusedIndexes = vector<long long> (length-1);

    random_device rd;
    mt19937 mer(rd());


    for (long long i = 0; i < length - 1; i++) {
        unusedIndexes[i] = i + 1;
    }

    int currentIndex = 0;

    for (long long i = 0; i < length - 1; i++) {
        long long r = mer() % unusedIndexes.size();
        long long nextInd = unusedIndexes[r];
        unusedIndexes = remove(unusedIndexes, r);
        result[currentIndex] = nextInd;
        currentIndex = nextInd;
    }

    return result;
}

double benchmarkLatency(long long sizeBytes, long long iterations) {
    vector<long long> arr = init(sizeBytes / 4);
    long long pointer = 0;

    auto begin = chrono::steady_clock::now();

    for (long long i = 0; i < iterations; i++) {
        pointer = arr[pointer];
    }

    auto end = chrono::steady_clock::now();
    auto diff = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return diff.count() / (double)iterations;
}

int main()
{
    ofstream out("data.txt");

    //200000 10000000
    for (double i = 5000; i < 2000000; i *= 1.2) {
        out << (long long)i << " " << benchmarkLatency((long long)i, 100000000) << "\n";
    }

    return 0;
}