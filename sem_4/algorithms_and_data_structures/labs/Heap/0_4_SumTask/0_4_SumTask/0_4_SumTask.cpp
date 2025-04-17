// 0_4_SumTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>
#include <string>

/*
	������������� sqrt-�������������.
	�������� ���� ������ �� sqrt(n) ������ ���������� ����� (���� �� ������� �������)
	������� ���������� ����� ��� ������� ����� - O(n)
	���� ����� ������ FindSum x y - ������ ����� ������, �������� � ������������ [x, y) � ������� "������"
	���� ����� ������ Add i, x - ����� ���� � ������� ��������� ������� � �������� i � �������� � ��� ����� x

	������. �� ������ 2/24 �����.
	������?

*/
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n;
	long long q;
	cin >> n;
	vector<long long> a(n);
	//������ �������� ������
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}

	//����������
	long long s = sqrt(n) + 1;
	vector<long long> b(s);
	for (long long i = 0; i < n; i++) {
		b[i / s] += a[i];
	}

	//������ �������
	cin >> q;
	string mode;
	long long l, r, x, index;
	vector<long long> result(q, numeric_limits<long long>::max());
	long long count = 0;		//����� �������

	for (long long i = 0; i < q; i++) {
		cin >> mode;
		if (mode == "FindSum") {
			result[count] = 0;
			cin >> l >> r;
			r--;
			for (long long j = l; j <= r;) {
				if (j % s == 0 && j + s - 1 <= r) {
					result[count] += b[j / s];
					j += s;
				}
				else {
					result[count] += a[j];
					j++;
				}
			}
			count++;
		}
		else if (mode == "Add") {
			cin >> index >> x;
			b[index / s] += x;
			a[index] += x;
		}
	}

	for (long long i : result) {
		if (i != numeric_limits<long long>::max()) {
			cout << i << "\n";
		}
	}
	return 0;
}

/*
5
10 30 40 -10 20
4
FindSum 1 2
FindSum 1 3
FindSum 1 4
FindSum 3 5

8
10 30 40 -10 20 0 0 0
4
FindSum 1 2
FindSum 1 3
FindSum 1 4
FindSum 3 5

5
10 30 40 -10 20
1
FindSum 3 5

5
10 30 40 -10 20
2
Add 0 -10
FindSum 0 4

5
0 0 0 0 0
2
FindSum 2 5
Add 3 8
*/