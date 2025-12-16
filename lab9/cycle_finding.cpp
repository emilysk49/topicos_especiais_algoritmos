#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <queue>
#include <tuple>
#include <cstring>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <iomanip>
#include <cmath>


using namespace std;

const long long INF = 1e15;

int main() {
    int vertices, arestas;
    cin >> vertices >> arestas;
    vector<tuple<int, int, long long>> adj(arestas);
    
    for (int i = 0; i < arestas; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[i] = {u, v, c};
    }

    vector<long long> dist(vertices+1, -1);
    vector<int> pai(vertices+1, -1);

    // bellman-ford
    int x;
    for (int i = 0; i < vertices; i++) {
        x = -1;
        for (auto [u, v, custo] : adj) {
            if (dist[v] > dist[u] + custo) {
                dist[v] = max(-INF, dist[u] + custo);
                pai[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        cout << "NO";
    else {
        cout << "YES" << endl;
        int y = x;
        for (int i = 0; i < vertices; ++i)
            y = pai[y];

        vector<int> path;
        for (int cur = y;; cur = pai[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1) {
                cout << path[i] << endl;
            } else {
                cout << path[i] << ' ';
            }
        }
    }
}