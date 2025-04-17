#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <cassert>

struct Point {
	int x;
	int y;
	int xNdx;
};

struct SingleX {
	int x;
	int cnt;
};

struct PointCmp {
	bool operator()(Point lhs, Point rhs) {
		if (lhs.y != rhs.y) {
			return lhs.y > rhs.y;
		}
		return lhs.x < rhs.x;
	}
};

int Solve(int n, int w, int h, const std::vector<Point>& trees, const std::vector<int>& xs, int curY) {
	//std::cerr << "curY = " << curY << '\n';
	std::vector<int> treeCntWithCX(xs.size());
	for (auto tree : trees) {
		if (tree.y <= curY) {
			break;
		}
		treeCntWithCX[tree.xNdx]++;
	}

	int maxLen = 0;
	int lastX = 0;
	for (size_t i = 0; i < xs.size(); ++i) {
		if (treeCntWithCX[i] > 0) {
			maxLen = std::max(maxLen, xs[i] - lastX);
			lastX = xs[i];
		}
	}
	maxLen = std::max(maxLen, w - lastX);
	int ans = maxLen * (h - curY);

	std::list<SingleX> treeCntWithXList;
	std::vector<std::list<SingleX>::iterator> treeCntWithXPos(xs.size(), treeCntWithXList.end());

	for (size_t i = 0; i < xs.size(); ++i) {
		if (treeCntWithCX[i] > 0) {
			treeCntWithXList.push_back({ xs[i], treeCntWithCX[i] });
			treeCntWithXPos[i] = std::prev(treeCntWithXList.end());
		}
	}

	for (auto tree : trees) {
		if (tree.y <= curY) {
			break;
		}
		auto it = treeCntWithXPos[tree.xNdx];
		assert(it != treeCntWithXList.end());
		assert(it->cnt > 0);
		--it->cnt;
		if (it->cnt == 0) {
			int leftBound, rightBound;
			if (it != treeCntWithXList.begin()) {
				leftBound = std::prev(it)->x;
			} else {
				leftBound = 0;
			}
			if (std::next(it) != treeCntWithXList.end()) {
				rightBound = std::next(it)->x;
			} else {
				rightBound = w;
			}
			maxLen = std::max(maxLen, rightBound - leftBound);
			treeCntWithXList.erase(it);
		}
		ans = std::max(ans, maxLen * (tree.y - curY));
	}
	return ans;
}

int main1() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n, w, h;
	fin >> n >> w >> h;
	std::vector<Point> trees(n);
	std::vector<int> xs;
	std::vector<int> ys;

	for (int i = 0; i < n; ++i) {
		fin >> trees[i].x >> trees[i].y;
		xs.push_back(trees[i].x);
		ys.push_back(trees[i].y);
	}
	std::sort(trees.begin(), trees.end(), PointCmp());

	std::sort(xs.begin(), xs.end());
	xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
	for (int i = 0; i < n; ++i) {
		trees[i].xNdx = std::lower_bound(xs.begin(), xs.end(), trees[i].x) - xs.begin();
	}

	int ans = Solve(n, w, h, trees, xs, 0);
	for (int y : ys) {
		ans = std::max(ans, Solve(n, w, h, trees, xs, y));
	}
	fout << ans << '\n';
	return 0;
}