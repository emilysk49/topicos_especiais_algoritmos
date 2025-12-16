#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>

using namespace std;
int valor, qntNotas;
//[{indice, total}] = {valor pago, qnt notas}
map<pair<int, int>, pair<int, int>> memo;
vector<int> notas;
int maximo;

pair<int, int> backtracking(int indice, int total) {
    if (total >= valor) return {total, 0};

    if (indice == qntNotas) return {maximo + 1, maximo + 1};
    
    auto chave = make_pair(indice, total);
    if (memo.count(chave)) return memo[chave];

    // nao usar nota[indice]
    auto op1 = backtracking(indice+1, total);

    //usar nota[indice]
    auto op2 = backtracking(indice + 1, total + notas[indice]);

    if (op2.first != maximo+1) op2.second += 1;


    pair<int,int> melhor;
    if (op1.first < op2.first) {
        melhor = op1;
    } else if (op2.first < op1.first) {
        melhor = op2;
    } else if (op1.second < op2.second) {
        melhor = op1;
    } else {
        melhor = op2;
    }
    return memo[chave] = melhor;
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) { 
        cin >> valor >> qntNotas;

        notas.clear();
        notas.resize(qntNotas);

        maximo = 0;
        for (int i = 0; i < qntNotas; i++) {
            cin >> notas[i];
            maximo += notas[i];
        }

        memo.clear();
        auto resultado = backtracking(0, 0);
        cout << resultado.first << " " << resultado.second << endl;
    }
}