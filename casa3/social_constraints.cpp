#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    vector<tuple<int, int, int>> restricoes;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        int a1, a2, res;
        restricoes.clear();

        for (int i = 0; i < m; i++) {
            cin >> a1 >> a2 >> res;
            restricoes.push_back(make_tuple(a1, a2, res));
        }

        vector<int> adolecentes(n); // nomes* de adolecentes [0, 1, 2] (se n = 3)
        for (int i = 0; i < n; i++) adolecentes[i] = i;

        int contagem = 0;

        do {
            vector<int> posicao(n); // posicoes de adolecentes [pos_a1, pos_a2, pos_a3]
            bool deu = true;
            for (int i = 0; i < n; i++) posicao[adolecentes[i]] = i;

            for (auto &tr: restricoes) {
                int a1 = get<0>(tr);
                int a2 = get<1>(tr);
                int res = get<2>(tr);

                int distancia = abs(posicao[a1] - posicao[a2]);

                if (res > 0 && distancia > res) deu = false; 
                if (res < 0 && distancia < -res) deu = false;

                if (!deu) break;
            }
            if (deu) contagem++;
        } while (next_permutation(adolecentes.begin(), adolecentes.end()));

        cout << contagem << endl;

    }

}