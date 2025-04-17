#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lcs(vector<int> x, vector<int> y) {
	int n = x.size();
	int m = y.size();
	vector<vector<int>> f(n+1, vector<int>(m+1));

	for (int i = 0; i < n + 1; i++) {
		f[0][i] = 0;
	}
	for (int i = 0; i < m + 1; i++) {
		f[i][0] = 0;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			if (x[i-1] == y[j-1]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}

	vector<int> result;

	int i = n;
	int j = m;
	while (i != 0 && j != 0) {
		if (x[i-1] == y[j-1]) {
			result.push_back(x[i-1]);
			i--;
			j--;
		}
		else {
			if (f[i - 1][j] == f[i][j]) {
				i--;
			}
			else if (f[i][j - 1] == f[i][j]) {
				j--;
			}
		}
	}

	return result;
}


int main()
{
	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> y(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	vector<int> res = lcs(x, y);
	reverse(res.begin(), res.end());
	int lcsCount = res.size();
	cout << lcsCount << endl;

	vector<int> resultX(lcsCount);
	vector<int> resultY(lcsCount);

	int cur = 0;
	for (int i = 0; i < lcsCount; i++) {
		resultX[i] = find(x.begin() + cur, x.end(), res[i]) - x.begin();
		cur = resultX[i] + 1;
	}

	cur = 0;
	for (int i = 0; i < lcsCount; i++) {
		resultY[i] = find(y.begin() + cur, y.end(), res[i]) - y.begin();
		cur = resultY[i] + 1;
	}

	for (int i : resultX) {
		cout << i << " ";
	}
	cout << endl;

	for (int i : resultY) {
		cout << i << " ";
	}

	return 0;
}