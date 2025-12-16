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

int kmp(string s, int tam) {
    vector<int> pi(tam, 0);

    for (int i = 1; i < tam; ++i) {
        // tenta ve prefixo anterior
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            // recua se nao for igual
            j = pi[j - 1];
        }
        //encontrou mais uma caracter igual
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }

    int menorTam = tam - pi[tam - 1];
    int n;
    if (tam % menorTam == 0) {
        n = tam / menorTam;
    } else {
        n = 1;
    }

    return n;
}

int main() {
    string termo;

    while(cin >> termo) {
        if (termo == ".") break;
        int tam = termo.size();
        int resposta = kmp(termo, tam);
        cout << resposta << endl;
    }
}