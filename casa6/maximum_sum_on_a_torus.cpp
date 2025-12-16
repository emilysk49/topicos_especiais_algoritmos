#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int n;
        cin >> n;

        vector<vector<int>> torus(n, vector<int>(n));
        int n2 = n*2;
        vector<vector<long long>> matriz2n(n2, vector<long long>(n2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> torus[i][j];
                matriz2n[i][j] = torus[i][j];
                matriz2n[i][j+n] = torus[i][j];
                matriz2n[i+n][j] = torus[i][j];
                matriz2n[i+n][j+n] = torus[i][j];
            }
        }

        // cria matriz com somas de quadrados 
        vector<vector<long long>> somas(n2+1, vector<long long>(n2+1, 0));
        for (int i = 1; i <= n2; i++) {
            for (int j = 1; j <= n2; j++) {
                somas[i][j] = matriz2n[i-1][j-1] + somas[i-1][j] + somas[i][j-1] - somas[i-1][j-1];
            }
        }

        // percorrer quadrado dentro da matriz para verificar maior soma 
        long long maior = -101 * n * n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int i2 = i; i2 < i + n; i2++) {
                    for (int j2 = j; j2 < j + n; j2++) {
                        long long soma = somas[i2+1][j2+1] - somas[i][j2+1] - somas[i2+1][j] + somas[i][j];
                        maior = max(maior, soma);
                    }
                }
            }
        }
        cout << maior << endl;
    }
}