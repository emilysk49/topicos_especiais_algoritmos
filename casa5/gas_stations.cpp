#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int l, g;
    
    while (true) {
        cin >> l >> g;
        if (l == 0 && g == 0) break;

        vector<pair<int,int>> postos;
        int x, r, inicio, fim;
        for (int i = 0; i < g; i++) {
            cin >> x >> r;
            if (x-r < 0) {
                inicio = 0;
            } else {
                inicio = x - r;
            }
            if (x+r > l) {
                fim = l;
            } else {
                fim = x + r;
            }
            postos.push_back(make_pair(inicio,fim));
        }
        sort(postos.begin(), postos.end());

        int atual = 0;
        int quantidade = 0;
        int i = 0;
        bool cobre = true;
        while (atual < l) {
            int melhor = atual;
            // x <= atual
            while (i < g && postos[i].first <= atual) {
                // pega o que vai mais longe
                melhor = max(melhor, postos[i].second);
                i++;
            }

            if (melhor == atual) {
                cobre = false;
                break;
            }
            atual = melhor;
            quantidade++;
        }
        if (!cobre) {
            cout << "-1" << endl;
        } else {
            cout << g-quantidade << endl;
        }
    }
}