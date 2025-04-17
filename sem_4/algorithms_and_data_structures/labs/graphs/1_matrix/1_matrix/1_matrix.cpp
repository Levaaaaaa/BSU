// 1_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    ifstream in("input.txt");
    in >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int x, y;
    for (int i = 0; i < m; i++) {
        in >> x >> y;
        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;
    }
    in.close();

    ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << matrix[i][j] << " ";
        }
        out << "\n";
    }
    out.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
