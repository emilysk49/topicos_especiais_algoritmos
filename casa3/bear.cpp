#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

bool subconjuntos(int comprimento, vector<int> &conjunto, int i, int soma) {
    if (soma == comprimento) return true;

    if (i == conjunto.size()) return false; //nao achou ate o fim

    if (subconjuntos(comprimento, conjunto, i+1, soma)) return true; //nao pega

    if (subconjuntos(comprimento, conjunto, i+1, soma + conjunto[i])) return true; //pegar

    return false;
}

int main() {
    int casos, comprimento, quantidade, tamanho;
    cin >> casos;

    for (int c = 0; c < casos; c++) {

        cin >> comprimento >> quantidade;
        vector<int> metais;
        metais.resize(quantidade);

        for (int i = 0; i < quantidade; i++) {
            cin >> metais[i];
        }

        if (subconjuntos(comprimento, metais, 0, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}