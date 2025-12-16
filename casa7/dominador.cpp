#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>
#include <set>

using namespace std;

vector<vector<int>> grafo;

void dfs(int u, vector<bool> &visitados, int bloqueado) {
    if (u == bloqueado) return;
    visitados[u] = true;
    // para cada no conectado
    for (int v : grafo[u]) {
        // se nao foi visitado
        if (!visitados[v]) {
            dfs(v, visitados, bloqueado);
        }
    }
}

int main() {
    int casos;
    cin >> casos;
    for (int c = 0; c < casos; c++) {
        int qnt;
        cin >> qnt;
        grafo.assign(qnt, vector<int>());
        for (int i = 0; i < qnt; i++) {
            for (int j = 0; j < qnt; j++) {
                int x;
                cin >> x;
                if (x == 1) grafo[i].push_back(j);
            }
        }
        vector<bool> alcansaveis(qnt, false);
        dfs(0, alcansaveis, -1);

        vector<vector<char>> domin(qnt, vector<char>(qnt, 'N'));

        for (int i = 0; i < qnt; i++) {
            vector<bool> visitados(qnt, false);
            // dfs do 0, sem passar por no i
            dfs(0, visitados, i);

            // para cada nos
            for (int j = 0; j < qnt; j++) {
                // se no j eh alcansavel e (nao foi visitado bloqueando i ou i = j)
                // isso quer dizer que sempre precisa passar por i para chegar no j
                if (alcansaveis[j] && (!visitados[j] || i == j)) {
                    domin[i][j] = 'Y';
                }
            }
        }

        cout << "Case " << c+1 << ":" << endl;
        string bordas = "+" + string(qnt*2-1, '-') + "+";
        for (int i = 0; i < qnt; i++) {
            cout << bordas << endl;
            cout << "|";
            for (int j = 0; j < qnt; j++) {
                cout << domin[i][j] << "|";
            }
            cout << endl;
        }
        cout << bordas << endl;
    }
}