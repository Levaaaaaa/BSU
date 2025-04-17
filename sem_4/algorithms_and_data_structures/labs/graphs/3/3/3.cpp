// 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	long long n, m;
	ifstream in("input.txt");
	in >> n >> m;
	vector<list<long long>> list1(n+1, list<long long>());
	long long u, v;
	for (long long i = 0; i < m; i++) {
		in >> u >> v;
		list1[u].push_front(v);
		list1[v].push_front(u);
	}
	in.close();

	ofstream out("output.txt");
	for (long long i = 1; i <= n; i++) {
		out << list1[i].size() << " ";
		for (long long j : list1[i]) {
			if (list1[i].size() == 0) {
				out << 0 << " ";
			}
			else {
				out << j << " ";
			}
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
