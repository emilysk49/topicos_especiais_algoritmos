#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

vector<int> arvore[200000];
int n;
int resultado;

void dfs(int u, int prox, int subarvore[]) {
    subarvore[u] = 1;
    bool centroide = true;

    for (int v: arvore[u]) {
        if (v == prox) continue;
        dfs(v,u, subarvore);
        subarvore[u] += subarvore[v];
        if (subarvore[v] > n / 2) {
            centroide = false;
        }
    }
    if (n - subarvore[u] > n / 2) {
        centroide = false;
    }
    if (centroide) resultado = u;
}

int main() {
    cin >> n;
    int u, v;
    int subarvore[n+1];
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        arvore[u].push_back(v);
        arvore[v].push_back(u);
    }
    dfs(1,-1, subarvore);
    cout << resultado << "\n";
    return 0;
}