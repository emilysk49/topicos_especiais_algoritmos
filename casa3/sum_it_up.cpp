#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

int total, quantidade, contagem;
vector<vector<int>> somas;
vector<int> atual;

void subconjuntos(vector<int> &conjunto, int indice, int soma, vector<int> &atual, set<string> &resultados) {
    if (soma == total) {
        string s = "";
        for (int e = 0; e < atual.size(); e++) {
            if (e != 0) s += "+";
            s += to_string(atual[e]);
        }
        resultados.insert(s);
        return;
    };

    for (int i = indice; i < quantidade; i++) {
        if (soma + conjunto[i] <= total) {
            atual.push_back(conjunto[i]);
            subconjuntos(conjunto, i + 1, soma + conjunto[i], atual, resultados);
            atual.pop_back();
        }
    }
}

int main() {
    vector<int> conjunto;
    while (true) {
        cin >> total >> quantidade;
        if (quantidade == 0) break;

        conjunto.resize(quantidade);
        contagem = 0;
        set<string> resultados;
        atual.clear();

        for (int i = 0; i < quantidade; i++) {
            cin >> conjunto[i];
        }

        subconjuntos(conjunto, 0, 0, atual, resultados);

        cout << "Sums of " << total << ":" << endl;

        if (resultados.empty()) {
            cout << "NONE" << endl;
        } else {
            for (auto it = resultados.rbegin(); it != resultados.rend(); ++it) {
                cout << *it << endl;
            }
        }

    }
}