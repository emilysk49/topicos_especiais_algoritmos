#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <iomanip>

using namespace std;

int binaryLifting(vector<vector<int>> &niveis, int x, int k) {
    for (int j = 0; j < 20; j++) {
            if (x == -1) break;
            if (k & (1 << j)) {
                x = niveis[x][j];
            }
        }
        return x;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> niveis(n + 1, vector<int>(20, -1));
    niveis[1][0] = -1; // chefe da raiz nao tem

    for (int i = 2; i <= n; i++) {
        cin >> niveis[i][0];
    }

    // n <= 2⋅10^5 -> log2(n) mais ou menos 18 passos (no maximo 20 seria suficiente)
    for (int j = 1; j < 20; j++) {
        for (int v = 1; v <= n; v++) {
            if (niveis[v][j - 1] != -1) { // se nao eh raiz
                // pai do pai 
                niveis[v][j] = niveis[niveis[v][j - 1]][j - 1];
            }
        }
    }

    int funcionario, nivel;
    for (int i = 0; i < q; i++) {
        cin >> funcionario >> nivel;
        int res = binaryLifting(niveis, funcionario, nivel);
        cout << res << endl;
    }
}