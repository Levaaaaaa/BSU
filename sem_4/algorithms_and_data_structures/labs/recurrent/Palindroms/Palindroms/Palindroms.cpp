#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> Palindrom(string str) {
    size_t n = str.length();
    vector<vector<int>> matrix(n, vector<int>(n));
    matrix[0][0] = 1;
    for (int i = 0; i < n - 1; i++) {
        matrix[i][i] = 1;
        matrix[i][i + 1] = str[i] == str[i + 1] ? 2 : 1;
    }

    int d = 3;
    while (d <= n) {
        for (int i = 0; i <= n - d; i++) {
            int j = i + d - 1;
                if (str[i] == str[j]) {
                    matrix[i][j] = matrix[i + 1][j - 1] + 2;
                }
                else {
                    matrix[i][j] = max(matrix[i + 1][j], matrix[i][j - 1]);
                }
        }
        d++;
    }

    return matrix;
}

string redress(string s, vector<vector<int>> matrix) {
    string result = "";
    int i = 0, j = matrix.size() - 1;
    while (i <= j) {
        if (s[i] == s[j]) {
            result += s[i];
            i++;
            j--;
        }
        else if (matrix[i + 1][j] > matrix[i][j - 1]) {
            i++;
        }
        else {
            j--;
        }
    }

    int len = matrix[0][matrix.size() - 1];

    int resLen;
    if (len % 2 == 0) {
        resLen = result.length();
    }
    else {
        resLen = result.length() - 1;
    }
    for (int i = resLen - 1; i >= 0; i--) {
        result += result[i];
    }
    return result;
}
//aaabbb
//asdfsla
//asddfsa
//abbabb

int main()
{

    string str;
    ifstream in("input.txt");
    in >> str;
    in.close();
    //   cin >> str;
    int n = str.length();

    vector<vector<int>> matrix = Palindrom(str);
    ofstream out("output.txt");
    out << matrix[0][n - 1] << "\n" << redress(str, matrix);
    out.close();
    return 0;
}