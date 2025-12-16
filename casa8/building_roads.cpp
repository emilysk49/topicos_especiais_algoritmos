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

using namespace std;

vector<bool> visitado;
vector<vector<int>> grafo;

void dfs(int u) {
    visitado[u] = true;
    for (int v : grafo[u]) {
        if (!visitado[v]) dfs(v);
    }
}

int main() {
    int cidades, estradas;
    cin >> cidades >> estradas;

    grafo.resize(cidades+1);
    visitado.assign(cidades+1, false);

    for (int i = 0; i < estradas; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    vector<int> resposta;
    for (int i = 1; i <= cidades; i++) {
        if (!visitado[i]) {
            resposta.push_back(i);
            dfs(i);
        }
    }

    int qnt = resposta.size()-1;
    cout << qnt << endl;

    for (int i = 0; i < qnt; i++) {
        cout << resposta[i] << " " << resposta[i+1] << endl;
    }
}