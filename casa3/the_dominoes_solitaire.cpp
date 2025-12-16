#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int,int>> pecas;
vector<bool> usada;
int espacos, qntPecas, esqI, dirI, esqF, dirF;

bool backtracking(int indice, int atual) {
    if (indice == espacos) {
        return (atual == esqF);
    }

    for (int i = 0; i < qntPecas; i++) {
        if (!usada[i]) { // se a peca nao foi usada
            int p1 = pecas[i].first;
            int p2 = pecas[i].second;

            if (p1 == atual) { // se encaixa com lado p1
                usada[i] = true;
                if (backtracking(indice + 1, p2)) return true;
                usada[i] = false; // desfaz
            } else if (p2 == atual) { // se encaixa com lado p2
                usada[i] = true;
                if (backtracking(indice + 1, p1)) return true;
                usada[i] = false; // desfaz
            }
        }
    }

    return false;
}

int main() {
    cin >> espacos;
    while (true) {
        if (espacos == 0) break;
        cin >> qntPecas;

        pecas.clear();
        usada.assign(qntPecas, false);

        // (esqI, dirI) , ... , (esqF, dirF)
        cin >> esqI >> dirI;
        cin >> esqF >> dirF;

        for (int i = 0; i < qntPecas; i++) {
            int p1, p2;
            cin >> p1 >> p2;
            pecas.push_back({p1,p2});
        }

        if (backtracking(0, dirI)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        cin >> espacos;
    }

}