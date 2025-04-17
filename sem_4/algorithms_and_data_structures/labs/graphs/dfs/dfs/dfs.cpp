// dfs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int counter = 1;
void dfs(int v, vector<vector<int>>& g, vector<bool>& visited, vector<int> &marks) {
	visited[v] = true;
	marks[v] = counter++;
	for (int u = 1; u < g.size(); u++) {
		if (g[v][u] && !visited[u]) {
			dfs(u, g, visited, marks);
		}
	}
}

int main()
{
	ifstream in("input.txt");
	int n;
	in >> n;
	n++;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			in >> g[i][j];
		}
	}
	in.close();
	vector<bool> visited(n, false);
	vector<int> marks(n, 0);
	
	for (int i = 1; i < n; i++) {
		if (!visited[i]) {
			dfs(i, g, visited, marks);
		}
	}

	ofstream out("output.txt");
	for (int i = 1; i < n; i++) {
		out << marks[i] << " ";
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
