// Period.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	ifstream in("input.txt");
	in >> n;
	string str;
	in >> str;
	in.close();

	vector<int> p(n, 0);
	//build prefix function

	int k = 0;
	ofstream out("output.txt");
	for (int i = 1; i < n; i++) {
		k = p[i - 1];
		while (k > 0 && str[k] != str[i]) {
			k = p[k - 1];
		}
		if (str[k] == str[i]) {
			p[i] = k + 1;
		}
		else {
			p[i] = k;
		}

		if (i+1 <= 2 * p[i]) {
			int t = i - p[i] + 1;
			if ((i+1) % t == 0) {
				out << i+1 << " " << (i+1) / t << "\n";
			}
		}
	}

	out.close();
	return 0;
}
