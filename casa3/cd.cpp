#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

int n, quantidade;
int mais_proximo;
vector<int> melhor_somas;
vector<int> atual;

void subconjuntos(vector<int> &atual, vector<int> &faixas, int indice, int atualSoma) {
    // se a soma atual eh melhor, atualiza
    if (atualSoma > mais_proximo) {
        mais_proximo = atualSoma;
        melhor_somas = atual;
    }

    // tentar adicionar cada numero restante respeitando limite N
    for (int i = indice; i < quantidade; i++) {
        if (atualSoma + faixas[i] <= n) {
            atual.push_back(faixas[i]); // inclui na soma
            subconjuntos(atual, faixas, i + 1, atualSoma + faixas[i]);
            atual.pop_back();
        }
    }
}

int main() {
    int faixa;

    while (cin >> n) {
        cin >> quantidade;
        vector<int> faixas(quantidade);
        mais_proximo = 0;
        melhor_somas.clear();
        atual.clear();
        
        for (int i = 0; i < quantidade; i++) {
            cin >> faixas[i];
        }
        subconjuntos(atual, faixas, 0, 0);

        for (int x : melhor_somas) {
            cout << x << " ";
        }
        cout << "sum:" << mais_proximo << endl;
    }
    return 0;
}