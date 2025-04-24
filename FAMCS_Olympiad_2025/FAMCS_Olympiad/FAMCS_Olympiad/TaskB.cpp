#include <fstream>

using namespace std;

long long full(long long n) {
	return n * (n - 1) / 2;
}
int main() {
	ifstream fin("camp.in");
	long long n, m;
	fin >> n >> m;
	fin.close();

	ofstream fout("camp.out");
	long long mx = full(n - m + 1);
	long long mn = (n % m) * full(n / m + 1) + (m - n % m) * full(n / m);

	fout << mn << " " << mx;
	fout.close();
	return 0;
}