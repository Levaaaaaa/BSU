// destroy_ways_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> set;
int FindSet(int x) {
	//int k = x;
	if (set[x] <= 0) {
		return x;
	}
	/*
	while (set[k] > 0) {
		k = set[k];
	}
	*/
	return FindSet(set[x]);
}

bool Union(int x, int y) {
	int min_lead = FindSet(x);
	int max_lead = FindSet(y);

	if (min_lead == max_lead) {
		return false;
	}

	/*
	int min_lead = set[lead1] <= set[lead2] ? lead2 : lead1;
	int max_lead = set[lead1] > set[lead2] ? lead2 : lead1;
	*/

	if ((-set[min_lead]) > (-set[max_lead])) {
		swap(min_lead, max_lead);
	}

	set[max_lead] += set[min_lead];
	set[min_lead] = max_lead;

	return true;
}

int main()
{
	long long n, m, q;
	ifstream in("input.txt");

	std::ios_base::sync_with_stdio(false);
	in.tie(nullptr);

	in >> n >> m >> q;
	m++;
	n++;
	vector<pair<int, int>> ways(m);

	int u, v;
	for (int i = 1; i < m; i++) {
		in >> ways[i].first >> ways[i].second;
	}

	vector<int> destroed_ways(q);
	vector<bool> will_destroed(m, false);
	//int t;
	for (int i = 0; i < q; i++) {
		in >> destroed_ways[i];
//		destroed_ways[i] = t;
		will_destroed[destroed_ways[i]] = true;
	}

//	in.close();

	int component_count = n-1;
	set = vector<int>(n, -1);
	for (int i = 1; i < m; i++) {
		if (!will_destroed[i]) {
			if (Union(ways[i].first, ways[i].second)) {
				component_count--;
			}
		}
	}
	
	vector<bool> result(q, true);

	for (int i = q - 1; i >= 0; i--) {
		if (component_count == 1) {
			result[i] = true;
			break;
		}
		result[i] = false;
		pair<int, int> way = ways[destroed_ways[i]];
		if (Union(ways[destroed_ways[i]].first, ways[destroed_ways[i]].second)) {
			component_count--;
		}
	}

	ofstream out("output.txt");
	out.tie(nullptr);
	for (int i = 0; i < q; i++) {
		out << result[i] ? 1 : 0;
	}

//	out.close();
	return 0;
}