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

using namespace std;

int main() {
    int inicio, fim, qnt;
    int caso = 1;

    while (true) {
        cin >> inicio >> fim >> qnt;

        if (inicio == 0 && fim == 0 && qnt == 0) break;

        vector<int> botoes;
        for (int i = 0; i < qnt; i++) {
            int botao;
            cin >> botao;
            botoes.push_back(botao);
        }
        
        if (inicio == fim) {
            cout << 0 << endl;
            continue;
        }
        
        vector<int> dist(10000, -1);
        queue<int> fila;
        fila.push(inicio);
        dist[inicio] = 0;
        bool achou = false;
        int resposta = 0;

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            for (int v : botoes) {
                int proximo = (atual + v) % 10000;
                if (dist[proximo] == -1) {
                    dist[proximo] = dist[atual] + 1;
                    if (proximo == fim) {
                        achou = true;
                        resposta = dist[proximo];
                        break;
                    }
                    fila.push(proximo);
                }
            }
            if (achou) break;
        }

        if (achou) {
            cout << "Case " << caso << ": " << resposta << endl;
        } else {
            cout << "Case " << caso << ": Permanently Locked" << endl;
        }
        caso++;
    }
}