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

int lca(vector<vector<int>> &niveis, vector<int> &prof, int a, int b) {
    // garante que a seja mais profundo para subir
    if (prof[a] < prof[b]) swap(a, b);

    // sobe a ate ficar no mesmo nivel que b
    a = binaryLifting(niveis, a, prof[a] - prof[b]);

    if (a == b) return a;

    // subir juntos a e b
    for (int j = 19; j >= 0; j--) {
        if (niveis[a][j] != -1 && niveis[a][j] != niveis[b][j]) {
            a = niveis[a][j];
            b = niveis[b][j];
        }
    }

    return niveis[a][0];
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> niveis(n + 1, vector<int>(20, -1));
    niveis[1][0] = -1; // chefe da raiz nao tem
    vector<int> prof(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> niveis[i][0];
        prof[i] = prof[niveis[i][0]] + 1;
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

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int res = lca(niveis, prof, a, b);
        cout << res << endl;
    }
}