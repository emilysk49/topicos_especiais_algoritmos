#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;
using int64 = long long;
int64 n;
vector<int64> fibonacci;
vector<pair<int, int64>> combinacoes;
unordered_map<int64, string> memo;
// string menor = "";

void criarFib(int64 n) {
    fibonacci.push_back(1);
    fibonacci.push_back(2);

    while(true) {
        int len = fibonacci.size();
        int64 proximo = fibonacci[len-1] + fibonacci[len-2];
        if (proximo > n) break;
        fibonacci.push_back(proximo);
    }

    for (int i = 1; i < fibonacci.size(); i++) {
        combinacoes.push_back({i, fibonacci[i]});
    }
    //sort(combinacoes.begin(), combinacoes.end());
}

string fatoracao(int64 atual) {
    if (atual == 1) return "";
    if (memo.count(atual)) return memo[atual];

    string melhor = "~"; // string "maior"
    for (auto &p : combinacoes) {
        int qntA = p.first;
        int64 f = p.second;
        if (atual % f == 0) {
            string resto = fatoracao(atual / f);
            if (resto != "~") {
                string candidato(qntA, 'A');
                candidato.push_back('B');
                candidato += resto;
                if (candidato < melhor) melhor = candidato;
            }
        }
    }
    return memo[atual] = melhor;
}

int main() {
    cin >> n;

    criarFib(n);
    string resposta = fatoracao(n);

    if (resposta == "~") {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << resposta << endl;
    }

    return 0;
}