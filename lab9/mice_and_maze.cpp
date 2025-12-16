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
vector<vector<pair<int,int>>> invert;
vector<tuple<int,int,int>> conexao;

vector<int> dijkstra(int origem, int cidades, vector<vector<pair<int,int>>> &grafo) {
    vector<int> custos(cidades+1, INF);
    // fila que tem par (custo, no) vai está ordenado por menor valor de custo
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;

    custos[origem] = 0;
    fila.push({0, origem});

    while (!fila.empty()) {
        int c = fila.top().first;
        int cid = fila.top().second;
        fila.pop();

        if (c > custos[cid]) continue;

        for (auto aresta : grafo[cid]) {
            int v = aresta.first;
            int p = aresta.second;
            // verifica se ir de origem -> ... -> cid -> v eh mais barato do que custo atual de v
            if (custos[v] > c + p) {
                custos[v] = c + p;
                fila.push({custos[v], v});
            }
        }
    }
    return custos;
}

int main() {
    int casos;
    cin >> casos;
    cin;

    for (int c = 0; c < casos; c++) {
        if (c != 0) cout << endl;
        int vertices, saida, limite, arestas;
        cin >> vertices >> saida >> limite >> arestas;

        invert.assign(vertices+1, {});
        conexao.clear();

        for (int i = 0; i < arestas; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            // invertido: a -> b fica b -> a
            invert[b].push_back({a, p});
            conexao.push_back({a, b, p});
        }

        vector<int> custo_destino = dijkstra(saida, vertices, invert);

        int resposta = 0;
        for (int c : custo_destino) {
            if (c != INF) {
                if (c <= limite) {
                    resposta++;
                }
            }
        }
        cout << resposta << endl;
    }
}