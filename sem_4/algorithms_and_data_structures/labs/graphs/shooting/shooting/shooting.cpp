// shooting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

int NULLEDGE = -1;

int dfs(int cur, int prev, vector<list<pair<int, int>>>& g, vector<bool> &visited) {
	int start = 0;

	if (visited[cur]) {
		start = cur;
		return start;
	}

	visited[cur] = true;
	for (pair<int, int> v : g[cur]) {
		if (prev != v.second) {
			start = dfs(v.first, v.second, g, visited);
			if (start != 0) {
				return start;
			}
		}
	}

	return start;
}

void dfs(int cur, int prevVertex, vector<list<pair<int, int>>>& g, vector<int>& result, vector<bool>& visited) {
	visited[cur] = true;
	for (pair<int, int> u : g[cur]) {
		if (u.second != prevVertex) {
			if (result[u.second] == NULLEDGE) {
				result[u.second] = u.first;
			}
			if (!visited[u.first]) {
				dfs(u.first, u.second, g, result, visited);
			}
		}
	}
}

int main()
{
	int R, C;
	ifstream in("input.txt");
	in >> R >> C;

	R++;
	C++;
	vector<list<pair<int, int>>> g(R, list<pair<int, int>>());

	//матрица смежности
	int u, v;
	for (int i = 1; i < C; i++) {
		in >> u >> v;
		g[u].push_back(pair<int, int>(v, i));
		g[v].push_back(pair<int, int>(u, i));
	}
	in.close();
	vector<int> result(C, NULLEDGE);
	vector<bool> visited(R, false);
	vector<bool> visited_for_dfs(R, false);
	ofstream out("output.txt");
	for (int i = 1; i < R; i++) {
		if (!visited[i]) {
			int start = dfs(i, NULLEDGE, g, visited);
			//check cycles
			if (start == 0) {
				out << "No";
				return 0;
			}

			//if graph has a cycle

			dfs(start, NULLEDGE, g, result, visited_for_dfs);
			visited_for_dfs = vector<bool>(R, false);
		}
	}
	for (int i = 1; i < C; i++) {
		out << result[i] << " ";
	}

	out.close();
	return 0;
}