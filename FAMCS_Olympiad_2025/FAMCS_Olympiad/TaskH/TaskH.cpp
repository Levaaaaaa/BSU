#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int sumCount(int s) {
	int l = 0, r = a.size() - 1, res = 0;
	int sum;
	while (l < r) {
		sum = a[l] + a[r];
		if (sum == s) {
			res++;
			l++;
			r--;
		}
		else if (sum > s) {
			r--;
		}
		else {
			l++;
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	a = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	int res = 0;
	for (int s = 2; s <= a[a.size() - 1] + a[a.size() - 2]; s++) {
		res = max(res, sumCount(s));
	}
	cout << res;
	return 0;
}