#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;
vector<vector<int>> terreno;
int n, m;

int buscaBinaria(vector<int> &linha, int limInf) {
    int inicio = 0;
    int fim = m-1;
    int resposta = m;

    while(inicio <= fim) {
        int medio = (inicio + fim) / 2;
        if (linha[medio] >= limInf) {
            resposta = medio;
            fim = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }
    return resposta;
}

int main() {
    cin >> n >> m;
    terreno.resize(n, vector<int>(m, 0));

    while (n != 0 || m != 0) {
        terreno.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> terreno[i][j];
            }
        }
        int qntIntervalo, menor, maior;
        cin >> qntIntervalo;
        for (int i = 0; i < qntIntervalo; i++) {
            cin >> menor >> maior;
            // vector<int> inferiores;
            // inferiores.resize(n);
            int maiorLado = 0;
            for (int linha = 0; linha < n; linha++) {
                int coluna = buscaBinaria(terreno[linha], menor);

                int resposta;
                int limLado = min(n-linha, m-coluna);

                if (coluna == m || terreno[linha][coluna] > maior) {
                    resposta = 0;
                    continue;
                } else {
                    resposta = 1;
                }

                for (int d = 1; d < limLado; d++) {
                    if (terreno[linha+d][coluna+d] <= maior) {
                        resposta++;
                    } else {
                        break;
                    }
                }

                if (maiorLado < resposta) {
                    maiorLado =  resposta;
                }

            }
            cout << maiorLado << endl;
        }
        cout << "-" << endl;
        cin >> n >> m;
    }
}