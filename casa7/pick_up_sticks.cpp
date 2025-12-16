#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <queue>

using namespace std;

int main() {
    while (true) {
        int qnt, nos;
        cin >> qnt >> nos;

        if (qnt == 0 && nos == 0) break;

        // grafo direcionado -> Ex - 1: [2,4]
        vector<vector<int>> arestas(qnt+1);
        // cada no com grau de entrada (Ex: no 2 tem 1 e 4 de entrada -> 2 grau de entrada)
        vector<int> emCimas(qnt+1, 0);

        for (int i = 0; i < nos; i++) {
            int cima, baixo;
            cin >> cima >> baixo;
            arestas[cima].push_back(baixo);
            emCimas[baixo]++;
        }

        queue<int> primeiros;
        for (int i = 1; i <= qnt; i++) {
            if (emCimas[i] == 0) {
                primeiros.push(i);
            }
        }

        vector<int> ordem;
        while (!primeiros.empty()) {
            int u = primeiros.front();
            primeiros.pop();
            ordem.push_back(u);
            for (int v : arestas[u]) {
                // para cada aresta de u -> remova essa aresta 
                // 1 : [2,3]
                // 2 : []
                // 3 : [4] ...
                // emCimas [0, 2, 1...] (no 2 -> 2 entradas e no 3 -> 1 entrada)
                // para u = 1 ent v = [2,3] -> emCimas [0, 1, 0, ...]o 
                emCimas[v]--;
                if (emCimas[v] == 0) primeiros.push(v);
            }
        }

        if (ordem.size() == qnt) {
            for (int x : ordem) {
                cout << x << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}