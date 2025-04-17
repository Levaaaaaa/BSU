// build_ways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

__int32 FindSet(vector<__int32>& set, __int32 x) {
	__int32 k = x;
	while (set[k] > 0) {
		k = set[k];
	}

	return k;
}

bool Union(vector<__int32>& set, __int32 x, __int32 y) {
	__int32 lead1 = FindSet(set, x);
	__int32 lead2 = FindSet(set, y);

	if (lead1 == lead2) {
		return false;
	}


	__int32 min_lead = set[lead1] <= set[lead2] ? lead2 : lead1;
	__int32 max_lead = set[lead1] > set[lead2] ? lead2 : lead1;

	set[max_lead] += set[min_lead];
	set[min_lead] = max_lead;

	return true;
}

int main()
{
	__int32 n;
	__int32 q;
	ifstream in("input.txt");
	ofstream out("output.txt");
	std::ios_base::sync_with_stdio(false);
	in.tie(nullptr);
	in >> n;
	in >> q;
	vector<__int32> cities(n+1, -1);

	__int32 x1, x2;
	__int32 result = n;
	for (__int32 i = 0; i < q; i++) {
		in >> x1 >> x2;
		if (Union(cities, x1, x2)) {	//если разные компоненты
			out << --n << "\n";
		}
		else {
			out << n << "\n";
		}
	}

	in.close();
	out.close();
	return 0;
}

/*
5 5
1 2
3 4
1 3
3 5
1 5
*/