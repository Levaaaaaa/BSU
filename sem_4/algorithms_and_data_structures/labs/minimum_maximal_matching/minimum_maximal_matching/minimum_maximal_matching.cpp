// minimum_maximal_matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

//vector<pair<long long, long long>> edges;
vector<bool> used;
list<long long> matching;
long long n, m;

int main()
{

	ifstream in("input.txt");

	std::ios_base::sync_with_stdio(false);
	in.tie(nullptr);

	in >> n >> m;
	n++;
//	edges = vector <pair<long long, long long>>(m);
	used = vector<bool>(n, false);

	long long u, v;
	for (int i = 0; i < m; i++) {
		in >> u >> v;
		if (!used[u] && !used[v]) {
			used[u] = true;
			used[v] = true;
			matching.push_back(i + 1);
		}
	}
	in.close();

	ofstream out("output.txt");

	out.tie(nullptr);

	out << matching.size() << "\n";

	for (long long edge : matching) {
		out << edge << "\n";
	}
	out.close();
	return 0;
}

