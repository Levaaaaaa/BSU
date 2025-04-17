// Hash_table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("input.txt");
	__int32 m, c, n;
	in >> m >> c >> n;
	vector<__int32> v(m, -1);

	__int32 x, index;
	for (__int32 i = 0; i < n; i++) {
		in >> x;
		index = ((x % m)) % m;
		for (__int32 j = 1; j < m && v[index] != -1; j++) {
			if (v[index] == x) {
				break;
			}
			index = ((x % m) + (c * j)) % m;
		}

		if (v[index] == x) {
			continue;
		}
		else if (v[index] == -1) {
			v[index] = x;
		}
	}

	in.close();

	ofstream out("output.txt");
	for (__int32 i = 0; i < m; i++) {
		out << v[i] << " ";
	}
	out.close();
	return 0;
}