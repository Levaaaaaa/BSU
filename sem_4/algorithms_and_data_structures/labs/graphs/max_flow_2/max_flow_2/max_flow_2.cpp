// max_flow_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Edge {
public:
    Edge() {

    }

    Edge(long long s, long long t, long long f, long long c) :
        source(s),
        target(t),
        flow(f),
        capacity(c) {

    }
    long long source;
    long long target;
    long long flow;
    long long capacity;
};

long long n, m;
vector<list<long long>> network;
vector<Edge> edges;
vector<list<long long>> layer_network;
vector<long long> d;
vector<bool> visited;


long long source(long long e);
long long target(long long e);
long long available(long long e);

void build_network() {
    long long u, v, w;
    for (long long i = 0; i < m; i++) {
        cin >> u >> v >> w;
        network[u].push_back(2 * i);
        network[v].push_back(2 * i + 1);
        edges[2 * i] = Edge(u, v, 0, w);
        edges[2 * i + 1] = Edge(v, u, 0, 0);
    }
}

void bfs() {
    long long start = 1;
    visited[start] = true;
    queue<long long> q;
    q.push(start);
    long long cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        long long u;
        for (long long e : network[cur]) {
            u = target(e);
            if (!visited[u] && available(e)) {
                d[u] = d[cur] + 1;
                q.push(u);
            }
        }
    }
}
void build_layer_network() {
    bfs();
    long long u, v;
    for (long long e = 0; e < 2*m; e++) {
        u = source(e);
        v = target(e);
        if (d[v] == d[u] + 1) {
            layer_network[u].push_back(2*e);
        }
    }
}

long long dfs(long long v, long long flow, long long t) {
    if (flow == 0) {
        return 0;
    }

    if (v == t) {
        return flow;
    }

    long long pushed;
    for (long long e : network[v]) {
        long long u = target(e);
        if (!visited[u]) {
            pushed = dfs(u, min(flow, available(e)), t);
            edges[e].flow += pushed;
            edges[e ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
long long find_block_f(long long s, long long t) {
    long long flow = 0;
    long long pushed = 0;
    do {
        pushed = dfs(s, LLONG_MAX, t);
        flow += pushed;
    } while (pushed > 0);
    return pushed;
}
long long dinic(long long s, long long t) {
    long long result = 0;
    while (true) {
        for (long long i = 1; i < n; i++) {
            visited[i] = true;
            d[i] = LLONG_MAX;
        }

        d[1] = 0;

        build_layer_network();

        if (d[t] == LLONG_MAX) {
            return result;
        }

        for (long long i = 1; i < n; i++) {
            visited[i] = false;
        }
        long long block_f = find_block_f(s,t);
        result += block_f;
    }

}
int main()
{
    cin >> n >> m;
    n++;

    network = vector<list<long long>>(n);
    edges = vector<Edge>(2*m);
    layer_network = vector<list<long long>>(n);
    d = vector<long long>(n);
    visited = vector<bool>(n);
    build_network();
    long long result = dinic(1, n - 1);
    cout << result;

    return 0;
}

long long source(long long e) {
    return edges[e].source;
}
long long target(long long e) {
    return edges[e].target;
}
long long available(long long e) {
    return edges[e].capacity - edges[e].flow;
}