#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

long long lisLength(vector<long long> a) {
	long long n = a.size();
	vector<long long> d(n + 1);
	d[0] = -LONG_MAX;
	for (long long i = 1; i <= n; i++) {
		d[i] = LONG_MAX;
	}

	for (long long i = 0; i < n; i++) {
		long long j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
		}
	}

	long long result = n;
	while (d[result] == LONG_MAX) {
		result--;
	}

	return result;
}

int main() {
	
	ifstream in("input.txt");
	long long n;

	in >> n;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
		in >> a[i];
	}

	in.close();

	ofstream out("output.txt");
	out << lisLength(a);
	out.close();

	return 0;
}