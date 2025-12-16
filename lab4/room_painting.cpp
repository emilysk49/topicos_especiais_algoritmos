#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int qntLatas, qntCores;

int buscaBinaria(vector<int> &lista, int quantidade) {
    int inicio = 0;
    int fim = qntLatas-1;
    int resposta = qntLatas;

    while(inicio <= fim) {
        int medio = (inicio + fim) / 2;
        if (lista[medio] >= quantidade) {
            resposta = medio;
            fim = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }
    return resposta;
}

int main() {
    cin >> qntLatas >> qntCores;
    vector<int> latas(qntLatas);
    //vector<int> cores(qntCores);
    int cor;
    long long soma = 0;

    for (int i = 0; i < qntLatas; i++) {
        cin >> latas[i];
    }
    sort(latas.begin(), latas.end());

    for (int i = 0; i < qntCores; i++) {
        cin >> cor;
        int lata = buscaBinaria(latas, cor);
        int quantidade = latas[lata];
        soma = soma + (quantidade - cor);
    }

    cout << soma << endl;
}