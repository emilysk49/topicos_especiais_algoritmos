#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int moduloB(const string &m, int n) {
    int resto = 0;
    for (char c : m) {
        int bit = c - '0';
        resto = (resto * 2 + bit) % n;
    }
    return resto;
}

void gerarCombinacao(string atual, int indice, vector<string> &divisores) {
    if (indice == atual.size()) { // se chegar no fim
        divisores.push_back(atual);
        return;
    }

    if (atual[indice] == '*') {
        // substituindo por 0
        atual[indice] = '0';
        gerarCombinacao(atual, indice + 1, divisores);
        // substituindo por 1
        atual[indice] = '1';
        gerarCombinacao(atual, indice + 1, divisores);

    } else {
        // mantem
        gerarCombinacao(atual, indice + 1, divisores);
    }
} 

int main() {
    string m, n;
    vector<string> divisores;
    cin >> m >> n;

    gerarCombinacao(n, 0, divisores);

    // posicoes de * no M
    vector<int> posicaoM;
    for (int i = 0; i < m.size(); i++)
        if (m[i] == '*') posicaoM.push_back(i);

    int astM = posicaoM.size();

    for (string div : divisores) {
        int inteiroDiv = 0;
        // transformar bits em int
        for (char c : div) inteiroDiv = inteiroDiv*2 + (c-'0');
        if (inteiroDiv == 0) continue;

        // se astM = 2: bit < 4 (2^astM)
        for (int bits = 0; bits < (1<<astM); bits++) {
            string dividendo = m;
            for (int i = 0; i < astM; i++) {
                // se bits = 2 e i = 1: (10>>1)&1 + 0 -> 01 & 1 + 0 -> 1
                dividendo[posicaoM[i]] = ((bits>>i)&1) + '0';
            }
            if (moduloB(dividendo, inteiroDiv) == 0) {
                cout << dividendo << endl;
                return 0;
            }
        }
    }

    return 0;

}