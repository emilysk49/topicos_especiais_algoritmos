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
    int casos = 1;
    int cruzamentos;
    while (cin >> cruzamentos) {
        vector<int> movimentacao(cruzamentos+1);
        for (int i = 1; i <= cruzamentos; i++) {
            cin >> movimentacao[i];
        }

        int ruas;
        cin >> ruas;
        vector<tuple<int, int, int>> arestas(ruas);
        for (int i = 0; i < ruas; i++) {
            int u, v;
            cin >> u >> v;
            int dif = movimentacao[v] - movimentacao[u];
            int custo = dif * dif * dif;
            arestas[i] = {u, v, custo};
        }

        int consul;
        cin >> consul;
        vector<int> consultas(consul);
        for (int i = 0; i < consul; i++) {
            cin >> consultas[i];
        }

        vector<long long> dist(cruzamentos+1, INF);
        dist[1] = 0;

        // bellman-ford
        for (int i = 1; i <= cruzamentos - 1; i++) {
            for (auto [u, v, custo] : arestas) {
                //se custo minimo atual para chegar no v (dist[v]) > custo de 1 ate u e depois u ate v
                if (dist[u] != INF && dist[v] > dist[u] + custo) {
                    dist[v] = dist[u] + custo;
                }
            }
        }

        //marca cruzamento com negativos
        vector<bool> neg(cruzamentos + 1, false);
        for (int i = 1; i <= cruzamentos - 1; i++) {
            for (auto [u, v, custo] : arestas) {
                if (dist[u] != INF && dist[v] > dist[u] + custo) {
                    dist[v] = -INF; // marca como negativamente infinito
                    neg[v] = true;
                }
            }
        }

        cout << "Set #" << casos++ << endl;
        for (int i = 0; i < consul; i++) {
            int destino = consultas[i];
            if (dist[destino] < 3 || dist[destino] == INF || neg[destino]) {
                cout << "?" << endl;
            } else {
                cout << dist[destino] << endl;
            }
        }
    }
}