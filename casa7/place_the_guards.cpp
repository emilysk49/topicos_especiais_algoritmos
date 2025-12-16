#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <sstream>
#include <cstring>

using namespace std;

vector<vector<int>> grafo;
vector<int> cores;
int cor0, cor1;
bool bipartido;

void dfs(int u, int cor) {
    cores[u] = cor;
    if (cor == 0) {
        // incrementa quantidade de cor0
        cor0++;
    } else {
        // incrementa quantidade de cor1
        cor1++;
    }

    for (int v : grafo[u]) {
        if (cores[v] == -1) {
            // se ainda nao foi colorido -> chama dfs com cor oposta
            dfs(v, 1 - cor);
        } else if (cores[v] == cor) {
            // se tem mesma cor que atual -> NAO bipartido
            bipartido = false;
        } 
    }
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int qnt, arestas;
        cin >> qnt >> arestas;

        grafo.clear();
        cores.clear();
        cores.assign(qnt, -1);
        grafo.assign(qnt, vector<int>());

        for (int i = 0; i < arestas; i++) {
            int a, b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        bool impossivel = false;
        int contagem = 0;
        for (int i = 0; i < qnt; i++) {
            if (cores[i] == -1) {
                cor0 = 0;
                cor1 = 0;
                bipartido = true;
                dfs(i, 0);

                if (!bipartido) {
                    impossivel = true;
                    break;
                }

                // se eh bipartido -> numero minimo de guardas
                if (cor0 + cor1 == 1) {
                    contagem += 1;
                } else {
                    contagem += min(cor0, cor1);
                }
            }
        }

        if (impossivel) {
            cout << "-1" << endl;
        } else {
            cout << contagem << endl;
        }
    }
}