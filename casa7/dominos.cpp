#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <sstream>
#include <stack>

using namespace std;

void dfs(int u, vector<vector<int>> &grafo, vector<bool> &visitado, stack<int> &ordem) {
    visitado[u] = true;
    for (int v : grafo[u]) {
        if (!visitado[v]) {
            dfs(v, grafo, visitado, ordem);
        }
    }
    //empilhar os nos na ordem de termino (de baixo para cima)
    ordem.push(u);
}

void dfs2(int u, vector<vector<int>> &grafoT, vector<int> &componentF, int id) {
    // marcar no da mesma componente fortemente conexo
    componentF[u] = id;
    for (int v : grafoT[u]) {
        if (componentF[v] == -1) {
            dfs2(v, grafoT, componentF, id);
        }
    }
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int qnt, arestas;
        cin >> qnt >> arestas;

        vector<vector<int>> grafo(qnt+1);
        vector<vector<int>> grafoT(qnt+1);
        for (int a = 0; a < arestas; a++) {
            int x, y;
            cin >> x >> y;
            grafo[x].push_back(y);
            grafoT[y].push_back(x); // transposta
        }

        vector<bool> visitado(qnt+1, false);
        int contagem = 0;
        stack<int> ordem;
        for (int i = 1; i <= qnt; i++) {
            if (!visitado[i]) {
                dfs(i, grafo, visitado, ordem);
            }
        }

        vector<int> componentF(qnt+1, -1);
        int id = 0;
        while (!ordem.empty()) {
            int u = ordem.top();
            ordem.pop();
            if (componentF[u] == -1) {
                dfs2(u, grafoT, componentF, id);
                id++;
            }
        }

        vector<int> anterior(id,0);
        for (int u = 1; u <= qnt; u++) {
            for (int v : grafo[u]) {
                // se u e v pertence no componente fortemente conexo diferente
                // incrementa anterior do componente v
                if (componentF[u] != componentF[v]) anterior[componentF[v]]++;
            }
        }

        int resp = 0;
        for (int i = 0; i < id; i++) {
            if (anterior[i] == 0) resp++;
        }

        cout << resp << endl;
    }
}