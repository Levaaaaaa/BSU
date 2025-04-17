// almost_increase_sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> reverse(vector<long long> v) {
	long long n = v.size();
	vector<long long> result(n);
	for (long long i = 0; i < n; i++) {
		result[n - i - 1] = v[i];
	}

	return result;
}

long long my_max(long long v1, long long v2) {
	if (v1 >= v2) {
		return v1;
	}
	return v2;
}

long long my_lower_bound(vector<long long>& v, long long a) {
	long long L = 0, R = v.size();
	long long C;

	while (L < R) {
		C = (L + R) >> 1;
		if (a > v[C]) {
			R = C;
		}
		else {
			L = C + 1;
		}
	}

	return L;
}

vector<long long> lisLengthEnd(vector<long long> a) {
	long long n = a.size();
	vector<long long> d(n + 1);
	d[0] = -LONG_MAX;
	for (long long i = 1; i <= n; i++) {
		d[i] = LONG_MAX;
	}

	vector<long long> z(n, 1);
	for (long long i = 0; i < n; i++) {
		long long j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
			z[i] = j;
		}
	}

	return z;
}

vector<long long> lisLengthBegin(vector<long long>& a) {
	a = reverse(a);
	long long n = a.size();
	vector<long long> d(n + 1);
	d[0] = LONG_MAX;
	for (long long i = 1; i <= n; i++) {
		d[i] = -LONG_MAX;
	}

	vector<long long> z(n, 1);
	for (long long i = 0; i < n; i++) {
		long long j = my_lower_bound(d, a[i]);
		if (d[j - 1] > a[i] && a[i] > d[j]) {
			d[j] = a[i];
			z[i] = j;
		}
	}


	int k = 2;

	return reverse(z);
}

void normalizeLisVector(vector<long long>& v) {
	long long n = v.size();
	for (long long i = n - 2; i >= 0; i--) {
		v[i] = my_max(v[i + 1], v[i]);
	}
}


long long add(vector<long long> &v1, vector<long long> &v2) {
	long long result = 1;
	for (long long i = 0; i < v1.size() - 1; i++) {
		result = my_max(result, v1[i] + v2[i + 1]);
	}

	return result;
}

int main()
{
	long long n;
	std::ifstream in("input.txt");
	in >> n;
	std::vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();

	ofstream out("output.txt");

	vector<long long> end = lisLengthEnd(a);
	vector<long long> beg = lisLengthBegin(a);
	normalizeLisVector(beg);
	out << add(end, beg);
	out.close();

	return 0;
}

/*
9
1 1 1 1 1 1 1 1 1

5
5 4 3 2 1
*/