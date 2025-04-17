// suffix_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	long long n;
	string str;

	cin >> str;
	str += '0' - 1;
	n = str.length();

	vector<long long> s(n);
	for (long long i = 0; i < n; i++) {
		s[i] = str[i] - '0' + 1;
		/*
		if (str[i] >= 48 && str[i] <= 57) {
			s[i] = str[i] - '0' + 1;
		}
		else if (str[i] >= 65 && str[i] <= 90) {
			s[i] = str[i] - 'A' + 1 + 10;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			s[i] = str[i] - 'a' + 1 + 36;
		}
		else if (str[i] == 0) {
			s[i] = 0;
		}
		*/
	}

	vector<long long> p(n), c(n);

//фаза 0
	
	long long k = 0;
	long long alphabet = 76;

	vector<long long> cnt(alphabet, 0);		//для сортировки подсчетом

	for (long long i = 0; i < n; i++) {
		cnt[s[i]]++;
	}

	for (long long i = 1; i < alphabet; i++) {	//см. сортировку подсчетом	
		cnt[i] += cnt[i - 1];
	}

	//формируем массив p
	for (long long i = 0; i < n; i++) {
		p[--cnt[s[i]]] = i;
	}

	//формируем массив c
	c[p[0]] = 0;
	long long classes = 1;
	for (long long i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i-1]]) {
			classes++;
		}
		c[p[i]] = classes - 1;
	}

//обрабатываем остальные log(n) фаз
	vector<long long> pn(n);		//вспомогательные массивы
	vector<long long> cn(n);
	for (int h = 0; (1 << h) < n; ++h) {
		//формируем pn
		for (long long i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) {
				pn[i] += n;
			}
		}

		//проведем сортировку подсчетом
		vector<long long> cnt1(classes, 0);
		for (long long j = 0; j < n; j++) {
			cnt1[c[pn[j]]]++;
		}

		for (long long j = 1; j < classes; j++) {
			cnt1[j] += cnt1[j - 1];
		}

		//обновляем p
		for (long long i = n-1; i >= 0; i--) {
			p[--cnt1[c[pn[i]]]] = pn[i];
		}

		cn[p[0]] = 0;
		classes = 1;
		for (long long i = 1; i < n; i++) {
			long long mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i-1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) {
				classes++;
			}
			cn[p[i]] = classes - 1;
		}

		for (long long i = 0; i < n; i++) {
			c[i] = cn[i];
		}
	}

	cout << n-1 << "\n";
	for (long long i = 0; i < n; i++) {
		if (p[i] != n-1) {
			cout << p[i] + 1 << " ";
		}
	}
	return 0;
}

/*
1211112

7
3 4 5 6 1 7 2
*/