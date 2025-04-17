#include <iostream>
#include <vector>

long long max(long long l1, long long l2) {
	if (l1 > l2) {
		return l1;
	}
	else {
		return l2;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		//visited[i] = false;
	}

	if (n == 2) {
		std::cout << -1;
		return 0;
	}

	if (n == 1) {
		std::cout << a[0] << std::endl;
		std::cout << 1;
		return 0;
	}

	std::vector<int> steps(n);
	std::vector<long long> f(n);
	f[0] = a[0];
	f[1] = -INT_MAX;
	f[2] = f[0] + a[2];
	steps[0] = -2;
	steps[1] = -1;
	steps[2] = 0;
	long long maxV;
	for (int i = 3; i < n; i++) {
		maxV = max(f[i - 3], f[i - 2]);
		if (maxV == f[i - 3]) {
			steps[i] = i - 3;
		}
		else {
			steps[i] = i - 2;
		}
		f[i] = maxV + a[i];
	}

	std::cout << f[n - 1] << "\n";

	int cur = steps[n - 1];
	std::vector<int> result(n);
	result[0] = n - 1;
	int j = 1;
	int stepCount = 0;
	while (cur != -2) {
		result[j] = cur;
		cur = steps[cur];
		j++;
	}
	j--;
	for (int i = j; i >= 0; i--) {
		std::cout << result[i] + 1 << " ";
	}
	return 0;
}