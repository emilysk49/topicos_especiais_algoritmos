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
#include <climits>

using namespace std;

vector<int> pai;
vector<int> pesos;

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

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int escolas, conexao;
        cin >> escolas >> conexao;

        vector<tuple<int, int, int>> arestas(conexao);
        for (int i = 0; i < conexao; i++) {
            int a, b, peso;
            cin >> a >> b >> peso;
            arestas[i] = {a-1, b-1, peso};
        }

        sort(arestas.begin(), arestas.end(), [](const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
            return get<2>(a) < get<2>(b); // compara pelo peso
        });

        pai.resize(escolas);
        pesos.assign(escolas, 0);
        for (int i = 0; i < escolas; i++) {
            pai[i] = i; //cada elemento começa em seu proprio conjunto
        }

        vector<int> mstArestas;
        int s1 = 0;
        int passo = -1;
        for (int i = 0; i < conexao; i++) {
            if (i == passo) continue;
            if (unir(get<0>(arestas[i]), get<1>(arestas[i]))) {
                s1 += get<2>(arestas[i]);
                mstArestas.push_back(i);
            }
        }

        int s2 = INT_MAX;
        // tenta remover cada uma das arestas do mst
        for (int indice : mstArestas) {
            // reset
            pai.resize(escolas);
            pesos.assign(escolas, 0);
            for (int i = 0; i < escolas; i++) pai[i] = i;

            int res = 0;
            int cnt = 0;
            for (int i = 0; i < conexao; i++) {
                if (i == indice) continue; // remove a aresta do mst original
                if (unir(get<0>(arestas[i]), get<1>(arestas[i]))) {
                    res += get<2>(arestas[i]);
                    cnt++;
                }
            }
            // verifica se a mst foi formada corretamente e pega o menor 
            if (cnt == escolas - 1) s2 = min(s2, res);
        }
        cout << s1 << " " << s2 << endl;
    }
}