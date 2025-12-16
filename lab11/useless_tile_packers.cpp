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

// Função para calcular área de polígono
double poligonoArea(const vector<pair<long long,long long>>& poli) {
    double area = 0;
    int n = poli.size();
    for(int i = 0; i < n; i++){
        int j = (i+1)%n;
        area += poli[i].first * poli[j].second - poli[j].first * poli[i].second;
    }
    return fabs(area)/2.0;
}

// produto vetorial
// resp > 0 : anti-horario
// resp < 0 horario
// resp = 0 colineares
long long cross(const pair<long long,long long> &O, const pair<long long,long long> &A, const pair<long long,long long> &B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

vector<pair<long long, long long>> convexHull(vector<pair<long long, long long>> P) {
    int qnt = P.size();
    int k = 0;
    if (qnt <= 1) return P;

    // ordenar e remover os duplicados
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    qnt = P.size();
    if (qnt <= 1) return P;

    vector<pair<long long, long long>> H(2*qnt);

    // parte inferior
    for (int i = 0; i < qnt; i++) {
        // enquanto houver pelo menos dois pontos no hull e a virada entre os 3 pontos:
        // H[k-2] → H[k-1] → P[i] (se horario ou colineares)=> Remove o ponto H[k-1]
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // parte superior
    int t = k;
    for (int i = qnt-2; i >= 0; i--) {
        while (k >= t+1 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    if (k > 1) H.resize(k-1); // remove duplicata do primeiro ponto

    // Garantir anti-horário: ponto com menor y (e x se empate) primeiro
    int inicio = 0;
    for (int i = 1; i < H.size(); i++) {
        if (H[i].second < H[inicio].second || 
           (H[i].second == H[inicio].second && H[i].first < H[inicio].first))
            inicio = i;
    }

    vector<pair<long long,long long>> rotacionado;
    for (int i = 0; i < H.size(); i++)
        rotacionado.push_back(H[(inicio+i) % H.size()]);

    return rotacionado;
}

int main() {
    int caso = 1;
    while (true) {
        int qnt;
        cin >> qnt;
        if (qnt == 0) break;

        // if (caso > 1) cout << endl;

        vector<pair<long long, long long>> pontos(qnt);
        for (int i = 0; i < qnt; i++) {
            cin >> pontos[i].first >> pontos[i].second;
        }

        double areaInicial = poligonoArea(pontos);

        vector<pair<long long, long long>> fecho = convexHull(pontos);

        double areaFecho = poligonoArea(fecho);

        double dif = areaFecho - areaInicial;

        double porcentagem = (dif*100)/areaFecho;

        cout << "Tile #" << caso << endl;
        caso++;
        cout << "Wasted Space = " << fixed << setprecision(2) << porcentagem << " %" << endl;
        cout << endl;
    }
}