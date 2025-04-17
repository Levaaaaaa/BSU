// ChristmasToy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<long long>> createBackpackMatrix(int W, long long n, vector<long long> w, vector<long long> p) {
    vector<vector<long long>> f(n + 1, vector<long long>(W + 1));

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= W; j++) {
            if (w[i-1] > j) {
                f[i][j] = f[i - 1][j];
            }
            else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i-1]] + p[i-1]);
            }
        }
    }

    return f;
}

vector<long long> redressSets(long long s, vector<long long> w, vector<long long> p, int n) {
    vector<long long> result(s, -1);
    vector<vector<long long>> f = createBackpackMatrix(n, s, w, p);
    long long i = f.size() - 1;
    int j = n;
    long long k = 0;
    while (f[i][j] != 0) {
        if (f[i - 1][j] == f[i][j]) {
            i--;
        }
        else {
            i--;
            j -= w[i];
            result[k] = i + 1;
            k++;
        }
    }

    for (long long i = result.size() - 1; result[i] == -1; i--) {
        result.erase(result.begin() + i);
    }

    return result;
}
int main()
{
    int n, m;
    long long s;
    ifstream in("input.txt");
    in >> s >> n >> m;
    vector<long long> w(s);
    vector<long long>p(s);

    for (long long i = 0; i < s; i++) {
        in >> w[i] >> p[i];
    }
    in.close();

    //vector<vector<long long>> matrix = createBackpackMatrix(n * m, s, w, p);
    vector<long long> result = redressSets(s, w, p, n * m);

    ofstream out("output.txt");
    out << result.size() << endl;
    for (long long i = result.size() - 1; i >= 0; i--) {
            out << result[i] << " ";
    }
    out.close();

    return 0;
}