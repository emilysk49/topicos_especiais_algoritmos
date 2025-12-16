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

const int MAXN = 200005;
int len[MAXN*2], link[MAXN*2];
long long contagem[MAXN*2];
map<char,int> prox[MAXN*2];

int qntEstado, ultimo;

void sufixoList(char c) {
    int atual = qntEstado++;
    len[atual] = len[ultimo] + 1;
    contagem[atual] = 1;
    prox[atual].clear();

    int p = ultimo;
    //Estado 2 ("aa")  --link--> Estado 1 ("a")  --link--> Estado 0 (vazio)
    while (p != -1 && !prox[p].count(c)) {
        prox[p][c] = atual;
        p = link[p];
    }

    if (p == -1) {
        link[atual] = 0;
    } else {
        int q = prox[p][c];
        if (len[p] + 1 == len[q]) {
            link[atual] = q;
        } else {
            int clone = qntEstado++;
            len[clone] = len[p] + 1;
            prox[clone] = prox[q];
            link[clone] = link[q];
            contagem[clone] = 0;

            while (p != -1 && prox[p][c] == q) {
                prox[p][c] = clone;
                p = link[p];
            }

            link[q] = link[atual] = clone;
        }
    }

    ultimo = atual;
}

long long exec() {
    vector<long long> tamCont(qntEstado,0);
    for (int i = 0; i < qntEstado; i++) tamCont[len[i]]++;
    for (int i = 1; i < qntEstado; i++) tamCont[i] += tamCont[i-1];

    vector<int> ordem(qntEstado);
    for (int i = qntEstado-1; i >= 0; i--) ordem[--tamCont[len[i]]] = i;

    for (int i = qntEstado-1; i > 0; i--) {
        int estado = ordem[i];
        contagem[link[estado]] += contagem[estado];
    }

    long long res = 0;
    for (int i = 1; i < qntEstado; i++) {
        long long rep = contagem[i];
        long long num_substr = len[i] - len[link[i]];
        res += rep * rep * num_substr;
    }
    return res;
}

int main() {
    int casos;
    cin >> casos;

    for (int caso = 0; caso < casos; caso++) {
        string s;
        cin >> s;

        qntEstado = 1;
        ultimo = 0;
        len[0] = 0;
        link[0] = -1;
        contagem[0] = 0;
        prox[0].clear();

        for (char c : s) {
            sufixoList(c);
        }
        cout << exec() << endl;
    }
}