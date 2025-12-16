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

int sobreposicao(string &antes, string &atual) {
    int tam = antes.size();
    int sobreposicao = 0;
    for (int i = 0; i <= tam; i++) {
        //CAT - ATE
        //i=1: substr(3-1=2) -> CA[T] ≠ [A]TE
        //i=2: substr(3-2=1) -> C[AT] = [AT]E
        if (antes.substr(tam-i) == atual.substr(0, i)) sobreposicao = i;
    }
    return sobreposicao;
}

int main() {
    int casos;
    cin >> casos;
    for (int c = 0; c < casos; c++) {
        int tam, qnt;
        cin >> tam >> qnt;

        int resposta = tam;
        string antes;
        for (int i = 0; i < qnt; i++) {
            string palavra;
            cin >> palavra;
            if (i > 0) {
                if (palavra == antes) continue;
                int sob = sobreposicao(antes, palavra);
                resposta += (tam - sob);
            }
            antes = palavra;
        }

        cout << resposta << endl;
    }
}