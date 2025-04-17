// circular_shift.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int main() {
	long long n;
	string s1, s2;

	ifstream in("input.txt");
	in >> n >> s1 >> s2;
	in.close();

	string general = s2 + "$" + s1 + s1;

	vector<long long> p(3 * n + 1);
	p[0] = 0;
	long long k;
	long long i;
	for (i = 1; i < 3 * n + 1 && p[i-1] != n; i++) {
		k = p[i - 1];
		while (k > 0 && general[k] != general[i]) {
			k = p[k - 1];
		}
		if (general[k] == general[i]) {
			p[i] = k+1;
		}
		else {
			p[i] = k;
		}
	}

	if (p[i - 1] != n) {
		i = -1;
	}
	else {
		i = i - 2 * n - 1;
	}

	ofstream out("output.txt");
	out << i;
	out.close();

	return 0;
}
/*
int main()
{
	long long n;
	string s1, s2;
	ifstream in("input.txt");
	in >> n >> s1 >> s2;
	in.close();

	uint64_t m = numeric_limits<uint64_t>::max();
	long long k = 29;
//	char separator = '$';

	vector<uint64_t> hashes1(3 * n);

	vector<uint64_t> k_degrees(3 * n);
	
	k_degrees[0] = 1;
	
	s1 = s2 + s1 + s1;

	hashes1[0] = s1[0] - 'a' + 1;
	for (long long i = 1; i < 3 * n; i++) {
		k_degrees[i] = (k_degrees[i - 1] * k) % m;
		hashes1[i] = (hashes1[i - 1] + (s1[i] - 'a' + 1) * k_degrees[i]) % m;
	}


	//activate magic
	long long r1 = n - 1, l2 = n, r2 = 2 * n - 1;
	long long counter = 0;
	for (counter = 0; r2 < 3 * n; counter++, r2++, l2++) {
		if (k_degrees[l2] * hashes1[r1] == (hashes1[r2] - hashes1[l2-1])) {
			break;
		}
	}
	if (r2 == 3 * n) {
		counter = -1;
	}

	ofstream out("output.txt");
	out << counter;
	out.close();

	return 0;
}
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
