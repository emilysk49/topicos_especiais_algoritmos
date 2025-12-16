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
    while (true) {
        int cruz, estradas;
        cin >> cruz >> estradas;

        if (cruz == 0 && estradas == 0) break;

        vector<tuple<int, int, int>> arestas(estradas);
        long long total = 0;
        for (int i = 0; i < estradas; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arestas[i] = {x, y, z};
            total += z;
        }

        sort(arestas.begin(), arestas.end(), [](const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
            return get<2>(a) < get<2>(b); // compara pelo peso
        });


        pai.resize(cruz);
        pesos.assign(cruz, 0);
        for (int i = 0; i < cruz; i++) {
            pai[i] = i; //cada elemento começa em seu proprio conjunto
        }

        long long mst = 0;
        for (auto [x, y, z] : arestas) {
            if (unir(x, y)) {
                mst += z;
            }
        }

        cout << total - mst << endl;
    }
}