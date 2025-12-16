#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
using namespace std;

int main() {

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        bool conflito = false;
        bitset<1000000> tempo;
        int inicio, fim, intervalo;

        for (int i = 0; i < n; i++) {
            cin >> inicio >> fim;
            for (int t = inicio; t < fim; t++){
                if (tempo[t] != 1) {
                    tempo.set(t);
                } else {
                    conflito = true;
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> inicio >> fim >> intervalo;
            int t_inicio = inicio;
            int t_fim = fim;
            while (t_inicio <= 1000000 && !conflito) {
                t_fim = min(t_inicio + (fim - inicio), 1000000);
                for (int t = t_inicio; t < t_fim; t++){
                    if (!tempo[t]) {
                        tempo.set(t);
                    } else {
                        conflito = true;
                        break;
                    }
                }
                t_inicio += intervalo;
            }
        }
        cout << (conflito ? "CONFLICT" : "NO CONFLICT") << endl;
    }
}