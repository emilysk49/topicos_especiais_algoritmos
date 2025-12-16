#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <iomanip>

using namespace std;

long long mergeCount(vector<int>& lista, int esquerda, int medio, int direita) {
    // se for esq = [3,5] e dir = [2,4] -- [3,5,2,4]
    // ent esquerda = 0, medio = 1 e direita = 3
    vector<int> temp(direita - esquerda + 1);
    // i = indice da esquerda e j = indice da direita
    int i = esquerda, j = medio + 1, k = 0;
    long long contagem = 0;

    // enquanto nao percorreu todos
    while(i <= medio && j <= direita) {
        // se nao tem inversao -> pegada esquerda e coloca na array temp
        if(lista[i] <= lista[j]) {
            temp[k++] = lista[i++];

        // se tem inversao -> pega da direita e coloca na array temp 
        } else {
            temp[k++] = lista[j++];
            // contagem é todo resto de valores que tem na esquerda
            contagem += (medio - i + 1);
        }
    }

    // pode sobrar ainda 
    while(i <= medio) temp[k++] = lista[i++];
    while(j <= direita) temp[k++] = lista[j++];

    for(int p = 0; p < k; p++) lista[esquerda + p] = temp[p];
    return contagem;
}

long long mergeSort(vector<int> &lista, int esquerda, int direita) {
    long long contagem = 0;

    if (esquerda < direita) {
        int medio = esquerda + (direita - esquerda) / 2;
        contagem += mergeSort(lista, esquerda, medio);
        contagem += mergeSort(lista, medio + 1, direita);
        contagem += mergeCount(lista, esquerda, medio, direita);
    }

    return contagem;
}

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> lista(n);
        for (int i = 0; i < n; i++) {
            cin >> lista[i];
        }

        long long trocas = mergeSort(lista, 0, n-1);
        if (trocas % 2) {
            cout << "Marcelo" << endl;
        } else {
            cout << "Carlos" << endl;
        }

    }
}