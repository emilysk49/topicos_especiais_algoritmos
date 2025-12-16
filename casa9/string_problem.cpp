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


using namespace std;

const int INF = 1e9;
int custos[26][26];

int main() {
    string s1, s2;
    int qnt;
    cin >> s1 >> s2 >> qnt;

    // grafo inicial com custos
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) {
                custos[i][j] = 0;
            } else {
                custos[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < qnt; i++) {
        char a, b;
        int custo;
        cin >> a >> b >> custo;
        int u = a - 'a';
        int v = b - 'a';
        custos[u][v] = min(custos[u][v], custo);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                //floyd warshall: verifica se passar por k eh mais barato que transformacao direta
                if (custos[i][k] < INF && custos[k][j] < INF) {
                    custos[i][j] = min(custos[i][j], custos[i][k] + custos[k][j]);
                }
            }
        }
    }

    if (s1.size() != s2.size()) {
        cout << -1 << endl;
        return 0;
    }

    string resposta = "";
    int total = 0;

    for (int i = 0; i < s1.size(); i++) {
        int u = s1[i] - 'a';
        int v = s2[i] - 'a';
        int menor_custo = INF;
        int melhor = -1;

        for (int c = 0; c < 26; c++) {
            //se ambas caracteres podem ser trocados por c
            if (custos[u][c] < INF && custos[v][c] < INF) {
                int custo = custos[u][c] + custos[v][c];
                // mantem o custo menor
                if (custo < menor_custo) {
                    menor_custo = custo;
                    melhor = c;
                }
            }
        }

        if (melhor == -1) {
            cout << -1 << endl;
            return 0;
        }

        resposta += char(melhor + 'a');
        total += menor_custo;
    }

    cout << total << endl;
    cout << resposta << endl;


}