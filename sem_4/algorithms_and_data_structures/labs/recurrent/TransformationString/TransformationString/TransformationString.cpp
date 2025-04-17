#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<long long>> transformLength(string s1, string s2, long long x, long long y, long long z) {
	int n = (int)s1.length();
	int m = (int)s2.length();
	vector<vector<long long>> result(n + 1, vector<long long>(m + 1));

	for (int i = 0; i <= n; i++) {
		result[i][0] = i * x;
	}

	for (int j = 0; j <= m; j++) {
		result[0][j] = j * y;
	}


	int k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			k = s1[i - 1] == s2[j - 1] ? 0 : 1;
			result[i][j] = min(result[i - 1][j] + x, min(result[i][j-1] + y, result[i-1][j-1] + k * z));
		}
	}

	return result;
}

int main() {
	long long x, y, z;
	string s1, s2;

	ifstream in("in.txt");
	in >> x >> y >> z >> s1 >> s2;
	in.close();

	ofstream out("out.txt");
	out << transformLength(s1, s2, x, y, z)[s1.length()][s2.length()];
	out.close();

	return 0;
}