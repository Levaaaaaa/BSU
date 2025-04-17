// Park.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int h, w;

class Point {
public:
	int first;
	int second;
	int x_num;
};

long long calc_max_space
(
	vector<Point> trees,
	int y_min,
	vector<int> xs,
	int global_result
)
{

	vector<int> x_counts(xs.size(), 0);
	for (int i = 0; i < trees.size(); i++) {
		if (trees[i].second <= y_min) {
			break;
		}
		x_counts[trees[i].x_num]++;
	}

	list<int> list_x(0);
	vector<list<int>::iterator> nodes(xs.size());

	
	for (int i = 0; i < xs.size(); i++) {
		if (x_counts[i] > 0) {
			list_x.push_back(xs[i]);
			nodes[i] = prev(list_x.end());
		}
	}
	if (list_x.empty()) {
		return max(global_result, (h - y_min) * w);
	}

	int max_delta_x = list_x.front();

	for (list<int>::iterator cur = next(list_x.begin()); cur != list_x.end(); cur++) {
		max_delta_x = max(max_delta_x, *cur - *prev(cur));
	}

	max_delta_x = max(max_delta_x, w - list_x.back());

	global_result = max(global_result, (h - y_min) * max_delta_x);

	for (Point tree : trees) {
		if (tree.second <= y_min) {
			break;
		}
		list<int>::iterator cur = nodes[tree.x_num];
		if (cur == list_x.end()) {
			continue;
		}
		if (x_counts[tree.x_num] <= 0) {
			continue;
		}

		x_counts[tree.x_num]--;
		if (x_counts[tree.x_num] == 0) {
			int x_left, x_right;

			if (cur == list_x.begin()) {
				x_left = 0;
			}
			else {
				x_left = *prev(cur);
			}

			if (next(cur) == list_x.end()) {
				x_right = w;
			}
			else {
				x_right = *next(cur);
			}

			max_delta_x = max(max_delta_x, x_right - x_left);
			list_x.erase(cur);
		}
		global_result = max(global_result, (tree.second - y_min) * max_delta_x);
	}
	return global_result;
}

int main()
{
	int n;
	ifstream in("input.txt");
	in >> n >> w >> h;
	if (n == 0) {
		ofstream out("output.txt");
		out << w * h;
		out.close();
		return 0;
	}
	vector<Point> trees(n);
	int tmp_x, tmp_y;
	int count = 0;
	vector<int> ys(n);
	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		in >> tmp_x >> tmp_y;
		//нет смысла рассматривать деревья, которые находятся на границе парка, т.к. они не ограничивают площадку
		if (tmp_x != 0 && tmp_x != w && tmp_y != 0 && tmp_y != h) {
			trees[count].first = tmp_x;
			trees[count].second = tmp_y;
			xs[i] = tmp_x;
			ys[i] = tmp_y;
			count++;
		}
		//#########################################
		else {
			trees.pop_back();
		}
		//##########################################
	}
	in.close();

	//сортируем деревья по убыванию у
	sort(trees.begin(), trees.begin() + trees.size(), [](Point p1, Point p2) {
		return p1.second != p2.second 
			? p1.second > p2.second 
			: p1.first < p2.first;
		});
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	//формируем список х
	//сжатие координат
	for (int i = 0; i < trees.size(); i++) {
		trees[i].x_num = lower_bound(xs.begin(), xs.end(), trees[i].first) - xs.begin();
	}

	//сортируем список по возрастанию х
	//сохраним число деревьев с каждым х, а затем удалим повторяющиеся х из списка



	
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	sort(ys.begin(), ys.end(), [](int y1, int y2) { return y2 < y1; });
	
	//предварительная подготовка завершена, начинаем алгоритм
	/*
		будем в цикле идти по уникальным значениям у, уменьшать число деревьев, находящихся на площадке и обновлять площадь
	*/
	int result = 1;
	for (int y_min : ys) {
				//достаём бубен
		result = calc_max_space(trees, y_min, xs, result);
	}

	//обработать когда у совпадает с нижней границей (аналогично выше)
	result = calc_max_space(trees, 0, xs, result);


	ofstream out("output.txt");
	out << result;
	out.close();
	return 0;
}