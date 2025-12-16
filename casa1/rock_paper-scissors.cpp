#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int vencedor(const string &m1, const string &m2) {
    if (m1 == m2)
        return 0;
    else if ((m1 == "rock" && m2 == "scissors") ||
             (m1 == "scissors" && m2 == "paper") ||
             (m1 == "paper" && m2 == "rock"))
        return 1;
    else
        return 2;
}

bool fim = false;

int main() {
    while (true) {
        int n, k;
        cin >> n;
        if (n == 0)
            break;
        cin >> k;

        if (fim) {
            printf("\n");
        }


        vector<vector<int>> resultados(n, vector<int>(2, 0));
        int partidas = k * n * (n - 1) / 2;

        for (int i = 0; i < partidas; ++i) {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;

            int resultado = vencedor(m1, m2);

            if (resultado == 1) {
                resultados[p1 - 1][0] += 1; // vitória
                resultados[p2 - 1][1] += 1; // derrota
            } else if (resultado == 2) {
                resultados[p1 - 1][1] += 1; // derrota
                resultados[p2 - 1][0] += 1; // vitória
            }
            // empate: nada a fazer
        }

        for (int i = 0; i < n; ++i) {
            int v = resultados[i][0];
            int d = resultados[i][1];
            int soma = v + d;
            if (soma == 0)
                printf("-\n");
            else
                printf("%.3f\n", (double)v / soma);
        }
        fim = true;
    }
    return 0;
}
