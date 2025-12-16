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

vector<int> pai;
vector<int> pesos;
vector<bool> visitado;
vector<vector<int>> grafo;

int achar(int x) {
    // encontra o pai lider ("raiz") do conjunto
    if (pai[x] != x) {
        pai[x] = achar(pai[x]);
    }
    return pai[x];
}

bool unir(int x, int y) {
    // achar os lideres
    int achouX = achar(x);
    int achouY = achar(y);

    // se os dois pertence no mesmo grupo -> nao precisa unir
    if (achouX == achouY) return false;

    // junta conjunto menor no maior
    if (pesos[achouX] < pesos[achouY]) {
        swap(achouX, achouY);
    }
    pai[achouY] = achouX;

    // se tem mesmo peso, aumenta seu peso
    if (pesos[achouX] == pesos[achouY]) {
        pesos[achouX]++;
    }
    return true;
} 

void dfs(int u) {
    visitado[u] = true;
    for (int v : grafo[u]) {
        if (!visitado[v]) dfs(v);
    }
}

int main() {

    int cidades, estradas;
    cin >> cidades >> estradas;

    vector<tuple<int, int, int>> arestas(estradas);
    grafo.resize(cidades);
    visitado.assign(cidades, false);
    for (int i = 0; i < estradas; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arestas[i] = {x-1, y-1, z};
        grafo[x-1].push_back(y-1);
        grafo[y-1].push_back(x-1);
    }


    sort(arestas.begin(), arestas.end(), [](const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
        return get<2>(a) < get<2>(b); // compara pelo peso
    });


    pai.resize(cidades);
    pesos.assign(cidades, 0);
    for (int i = 0;i < cidades; i++) {
        pai[i] = i; //cada elemento começa em seu proprio conjunto
    }

    long long mst = 0;
    int qnt = 0;
    for (auto [x, y, z] : arestas) {
        if (unir(x, y)) {
            mst += z;
            qnt++;
        }
    }

    if (qnt == cidades - 1) {
        cout << mst << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}