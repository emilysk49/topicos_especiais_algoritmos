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

int cidades, arestas;
vector<vector<pair<int, int>>> grafo;
const int INF = 1e9;

int camMaxCapacidade(int origem, int destino) {
    vector<int> capacidades(cidades+1, 0);
    priority_queue<pair<int,int>> fila; // (capacidade, cidade)
    capacidades[origem] = INF;
    fila.push({capacidades[origem], origem});

    while(!fila.empty()) {
        int cap = fila.top().first;
        int u = fila.top().second;
        fila.pop();

        if (u == destino) return cap;

        for (auto [v, p] : grafo[u]) {
            int novaCap = min(cap, p);
            if (novaCap > capacidades[v]) {
                capacidades[v] = novaCap;
                fila.push({novaCap, v});
            }
        }
    }
    return 0;
}

int main() {
    int casos = 1;
    while (true) {
        cin >> cidades >> arestas;
        if (cidades == 0 && arestas == 0) break;

        grafo.assign(cidades+1, {});
        for (int i = 0; i < arestas; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            grafo[u].push_back({v, p});
            grafo[v].push_back({u, p});
        }

        int origem, destino, pessoas;
        cin >> origem >> destino >> pessoas;

        int maxCap = camMaxCapacidade(origem, destino);
        int voltas = (pessoas + maxCap - 2) / (maxCap - 1);

        cout << "Scenario #" << casos++ << endl;
        cout << "Minimum Number of Trips = " << voltas << endl << endl;
        
    }
}