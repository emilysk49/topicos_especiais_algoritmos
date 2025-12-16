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
const int INF = 1e9;

int main() {
    int cruzamentos, estradas;
    int casos = 1;
    while (cin >> cruzamentos >> estradas) {
        vector<vector<pair<int,int>>> grafo(cruzamentos);
        for (int i = 0; i < estradas; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            grafo[u].push_back({v, d});
            grafo[v].push_back({u, d});
        }

        int consul;
        cin >> consul;

        vector<pair<int, int>> consultas(consul);
        for (int i = 0; i < consul; i++) {
            cin >> consultas[i].first >> consultas[i].second;
        }
        cout << "Set #" << casos++ << endl;

        for (auto c : consultas) {
            int origem = c.first;
            int destino = c.second;

            // dist[u][0] -> menor caminho de origem ate u
            // dist[u][1] -> segundo menor caminho de origem ate u
            vector<vector<int>> dist(cruzamentos, vector<int>(2, INF));
            // ordenar: cruzamento com menor distancia
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;

            dist[origem][0] = 0;
            // {distancia,cruzamento}
            fila.push({0, origem});

            while (!fila.empty()) {
                auto [distancia, u] = fila.top(); 
                fila.pop();

                // se distancia ja eh a maior que segundo menor -> ignora
                if (distancia > dist[u][1]) continue;

                // para cada vizinho de u
                for (auto [v, w] : grafo[u]) {
                    int nova_distancia = distancia + w;
                    // se a distancia nova eh menor que o menor ate agora -> atualiza
                    if (nova_distancia < dist[v][0]) {
                        dist[v][1] = dist[v][0];
                        dist[v][0] = nova_distancia;
                        fila.push({dist[v][0], v});
                        fila.push({dist[v][1], v});
                    // se distancia nova eh maior que menor mas menor que o segundo menor -> atualiza
                    } else if (nova_distancia > dist[v][0] && nova_distancia < dist[v][1]) {
                        dist[v][1] = nova_distancia;
                        fila.push({dist[v][1], v});
                    }
                }
            }

            if (dist[destino][1] == INF) {
                cout << "?" << endl;
            } else {
                cout << dist[destino][1] << endl;
            }
        }
    }
}