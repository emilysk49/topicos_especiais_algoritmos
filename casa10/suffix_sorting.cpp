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
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

int k;
int n_global;
vector<int> rank_global;

bool compara(int i, int j) {
    if (rank_global[i] != rank_global[j]) return rank_global[i] < rank_global[j];

    int ri, rj;
    if (i + k < n_global) {
        ri = rank_global[i + k];
    } else {
        ri = -1;
    }

    if (j + k < n_global) {
        rj = rank_global[j + k];
    } else {
        rj = -1;
    }
    return ri < rj;
}

vector<int> sufixoList(string &s) {
    int n = s.size();
    vector<int> sufixos(n), ordem(n), tmp(n);

    for (int i = 0; i < n; i++) {
        // guarda posicao inicial do sufixo 
        sufixos[i] = i;
        // ordem do caracetere s[i]
        // [b,a,n,a,n,a] -> [98,97,110,97,110,97] (ASCII)
        ordem[i] = s[i];
    }

    rank_global = ordem;
    n_global = n;

    // k = 1,2,4,8,...
    for (k = 1;; k <<= 1) {
        // ordena lexicograficamente (sem substring)
        sort(sufixos.begin(), sufixos.end(), compara);

        tmp[sufixos[0]] = 0;
        // se sufixo anterior eh menor que sufixo atual ordem + 1
        for (int i = 1; i < n; i++)
            tmp[sufixos[i]] = tmp[sufixos[i - 1]] + compara(sufixos[i - 1], sufixos[i]);
        ordem = tmp;
        rank_global = ordem;

        // se maior rank eh n-1 -> todos sufixo tem ordem distintos 
        if (ordem[sufixos[n - 1]] == n - 1) break;
    }
    return sufixos;
}

int main() {
    string termo;
    while (getline(cin, termo)) {
        int n;
        cin >> n;
        cin.ignore();

        vector<int> consultas(n);
        for (int i = 0; i < n; i++) cin >> consultas[i];
        cin.ignore();

        int tam = termo.size();
        vector<int> sufixos = sufixoList(termo);

        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << sufixos[consultas[i]];
        }
        cout << endl;
    }
}