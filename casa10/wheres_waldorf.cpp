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
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

// Direções: direita, esquerda, baixo, cima, diagonal baixo-direita, baixo-esquerda, cima-direita, cima-esquerda
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void buscar(vector<string> &matriz, string &palavra, int linha, int coluna) {
    int tam = palavra.size();
    bool achou = false;
    for (int i = 0; i < linha; i++) {
        if (achou) break;
        for (int j = 0; j < coluna; j++) {
            if (achou) break;
            for (int d = 0; d < 8; d++) {
                int auxi = i;
                int auxj = j;
                int c;
                for (c = 0; c < tam; c++) {
                    if (auxi < 0 || auxi >= linha || auxj < 0 || auxj >= coluna) break;
                    if (matriz[auxi][auxj] != palavra[c]) break;
                    auxi += dx[d];
                    auxj += dy[d];
                }
                if (c == tam) {
                    cout << i+1 << " " << j+1 << endl;
                    achou = true;
                    break;
                }
            }
        }
    }
}

int main() {
    int casos;
    cin >> casos;
    cin.ignore();
    cin.ignore();


    for (int c = 0; c < casos; c++) {
        if (c > 0) cout << endl;
        int linha, coluna;
        cin >> linha >> coluna;
        cin.ignore();

        vector<string> matriz(linha);

        for (int i = 0; i < linha; i++) {
            getline(cin, matriz[i]);
            transform(matriz[i].begin(), matriz[i].end(), matriz[i].begin(), ::tolower);
        }

        int qnt;
        cin >> qnt;

        vector<string> lista(qnt);
        for (int i = 0; i < qnt; i++) {
            cin >> lista[i];
            transform(lista[i].begin(), lista[i].end(), lista[i].begin(), ::tolower);
            buscar(matriz, lista[i], linha, coluna);
        }
    }
}