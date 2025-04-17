#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Edge {
public:
	Edge() {

	}

	Edge(int s, int t, long long c, long long f) :
		source(s),
		target(t),
		capacity(c),
		flow(f) {

	}
	int source;
	int target;
	long long capacity;
	long long flow;
};

int n, m;
vector<list<int>> g;
vector<Edge> edges;
vector<bool> visited;
vector<int> pred;

//сеть остаточных пропускных способностей
int source(int e);
int target(int e);
long long available(int e);
void push_edge(int e, long long flow);

void find_path(int s);
list<int> restore_path(int t);
long long min_capacity(list<int> path);
void push_path(list<int> path, long long flow);

long long ford_fulkerson(int s, int t) {
	long long result = 0;
	if (s == t) {
		return result;
	}

	while (true) {

		for (int i = 0; i < n; i++) {
			visited[i] = false;
			pred[i] = -1;
		}
		find_path(s);

		if (!visited[t]) {
			break;
		}

		list<int> path = restore_path(t);
		long long flow = min_capacity(path);
		push_path(path, flow);
		result += flow;
	}

	return result;
}

void build_network() {
	int u, v;
	long long w;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back(2*i);
		edges[2*i] = Edge(u, v, w, 0);
		g[v].push_back(2*i+1);
		edges[2 * i + 1] = Edge(v, u, 0, 0);	//?
	}
}
int main() {
	cin >> n >> m;
	n++;

	g = vector<list<int>>(n);
	edges = vector<Edge>(2*m);
	visited = vector<bool>(n, false);
	pred = vector<int>(n, -1);

	build_network();
	long long result = ford_fulkerson(1, n-1);
	cout << result;
	return 0;
}

int source(int e) {
	return edges[e].source;
}
int target(int e) {
	return edges[e].target;
}
long long available(int e) {
	return edges[e].capacity - edges[e].flow;
}
void push_edge(int e, long long flow) {
	edges[e].flow += flow;
	edges[e ^ 1].flow -= flow;
}

void find_path(int s) {
	visited[s] = true;
	for (int e : g[s]) {
		int u = target(e);
		if (!visited[u] && available(e) > 0) {
			pred[u] = e;
			find_path(u);
		}
	}
}

list<int> restore_path(int t) {
	list<int> result;
	while (pred[t] != -1) {
		result.push_back(pred[t]);
		t = source(pred[t]);
	}

	return result;
}

long long min_capacity(list<int> path) {
	long long min = available(path.front());
	for (int e : path) {
		if (available(e) < min) {
			min = available(e);
		}
	}

	return min;
}

void push_path(list<int> path, long long flow) {
	for (int e : path) {
		push_edge(e, flow);
	}
}