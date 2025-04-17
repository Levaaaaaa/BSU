// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <fstream>

using namespace std;

long long n, m;
long long sigi_reuven_function(long long start, vector<list<pair<long long, int>>> &g) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push(pair<long long, long long>(0, start));

    vector<long long> dist(n, LLONG_MAX);
    vector<bool> processed(n, false);

    while (!q.empty()) {
        pair<long long, long long> cur = q.top();   //(dv, v)
        q.pop();
        if (processed[cur.second]) {
            continue;
        }

        processed[cur.second] = true;
        dist[cur.second] = cur.first;

        for (pair<long long, int> p : g[cur.second]) {
            long long u = p.first;      //вершина
            int w = p.second;     //цена перехода
            if (!processed[u]) {
                q.push(pair<long long, long long>(cur.first + w, u));
            }
        }
    }

 
    return dist.back();
}

int main()
{
    ifstream in("input.txt");
    in >> n >> m;

    n++;
    long long u, v;
    int w;
    vector<list<pair<long long, int>>> g(n, list<pair<long long, int>>());
    for (long long i = 0; i < m; i++) {
        in >> u >> v >> w;
        g[u].push_back(pair<long long, int>(v, w));
        g[v].push_back(pair<long long, int>(u, w));
    }

    in.close();

    long long result = sigi_reuven_function(1, g);

    ofstream out("output.txt");
    out << result;
    out.close();

    return 0;
}