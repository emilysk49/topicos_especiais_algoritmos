#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <unordered_map>

using namespace std;
int soma, qntBarras, maxEst;

long long backtracking(int indice, int barraRest, unordered_map<long long, long long> &memo) {
    if (indice == qntBarras) {
        if (barraRest == 0) {
            return 1; //valida
        } else {
            return 0; //invalida
        }
    }

    // unordered map chave unica : junta indice e barraRestante
    long long chave = ((long long)indice << 32) | barraRest;
    if (memo.count(chave)) { // verifica se calculou numero de combinacoes para esse subproblema
        return memo[chave];
    }

    long long total = 0;
    for (int estensao = 1; estensao <= min(maxEst, barraRest); estensao++) {
        total += backtracking(indice + 1, barraRest - estensao, memo);
    }

    memo[chave] = total;
    return total;

}

int main() {
    while (cin >> soma >> qntBarras >> maxEst) {
        unordered_map<long long, long long> memo;
        long long total = backtracking(0, soma, memo);
        cout << total << endl;
    }
}