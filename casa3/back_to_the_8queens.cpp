#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> posicoes;
vector<int> atual;
int menorMov;

void backtracking(int coluna, int movimentos) {
    if (coluna == 8) {
        menorMov = min(menorMov, movimentos);
        return;
    }

    for (int linha = 1; linha <= 8; linha++) {
        bool conflito = false;
        // verifica coluna 
        for (int colunaAntes = 0; colunaAntes < coluna; colunaAntes++) {
            // diferenca de linhas e colunas da rainha X-1 e X sao iguais? (diagonal)
            // linha da rainha X-1 eh igual da X? (horizontal) 
            if (abs(atual[colunaAntes] - linha) == abs(colunaAntes - coluna) || atual[colunaAntes] == linha) {
                conflito = true;
                break;
            }
        }
        if (!conflito) {
            int movimentoExtra = (linha != posicoes[coluna]) ? 1 : 0;
            atual[coluna] = linha;
            backtracking(coluna + 1, movimentos + movimentoExtra);
        }
    }

}

int main() {

    int casos = 1;
    string entrada;

    posicoes.resize(8);
    atual.resize(8);

    while (true) {

        for (int i = 0; i < 8; i++) {
            int posRainha;
            if (cin >> posRainha) {
                posicoes[i] = posRainha;
            } else {
                return 0;
            }
        }
        menorMov = 8;
        atual.clear();
        backtracking(0,0);

        cout << "Case " << casos << ": " << menorMov << endl;
        casos++;
    }
}