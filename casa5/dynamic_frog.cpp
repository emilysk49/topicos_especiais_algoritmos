#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int casos;
    cin >> casos;
    // vector<int> respostas;

    for (int c = 0; c < casos; c++) {
        int qntPedras;
        long long distancia;
        cin >> qntPedras >> distancia;

        vector<long long> pedras;

        long long puloMaior = 0;
        long long anterior = 0;
        bool pulouMenor = false;

        for (int i = 0; i < qntPedras; i++) {
            string s;
            cin >> s;
            char tipo = s[0];
            // entrada = B-5, ignora "B-"
            long long posicao = stoll(s.substr(2));
            if (tipo == 'B') {
                if (puloMaior < (posicao - anterior)) {
                    puloMaior = posicao - anterior;
                }
                anterior = posicao;
                pedras.push_back(posicao);
            } else {
                if (!pulouMenor) {
                    pulouMenor = true;
                    if (puloMaior < (posicao - anterior)) {
                        puloMaior = posicao - anterior;
                    }
                    anterior = posicao;
                } else {
                    pedras.push_back(posicao);
                    pulouMenor = false;
                }
            }
        }
        if (pedras.empty()) {
            cout << "Case " << c+1 << ": " << distancia << endl;
            // respostas.push_back(distancia);
        } else {
            if (puloMaior < (distancia - anterior)) {
                puloMaior = distancia - anterior;
            }
            reverse(pedras.begin(), pedras.end());
            int contagem = 0;
            long long puloAntes;
            for (long long p : pedras) {
                if (contagem == 0) {
                    if (puloMaior < (distancia - p)) {
                        puloMaior = distancia - p;
                    }
                } else {
                    if (puloMaior < (puloAntes - p)) {
                        puloMaior = puloAntes - p;
                    }
                }
                contagem++;
                puloAntes = p;
            }
            if (puloMaior < puloAntes) puloMaior = puloAntes;
            cout << "Case " << c+1 << ": " << puloMaior << endl;    
            // respostas.push_back(puloMaior);
        }
    }
    // for (int i = 0; i < (int)respostas.size(); i++) {
    //     cout << "Case " << i+1 << ": " << respostas[i] << "\n";
    // }
}