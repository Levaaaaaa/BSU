// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	ifstream in("input.txt");
	in >> n;
	n++;
	int tmp;
	vector<int> marks(n, 0);
	int mark = 1;
	vector<bool> visited(n, false);
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	queue<int> q;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int tmp;
			in >> tmp;
			matrix[i][j] = tmp;
		}
	}
	
	for (int j = 1; j < n; j++) {
		if (visited[j]) {
			continue;
		}
		q.push(j);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			if (visited[v]) {
				continue;
			}
			visited[v] = true;
			marks[v] = mark++;

			for (int i = 1; i < n; i++) {
				if (matrix[v][i] && !visited[i]) {
					q.push(i);
				}
			}
		}
	}

	in.close();

	ofstream out("output.txt");
	for (int i = 1; i < n; i++)
	{
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
