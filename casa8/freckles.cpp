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


using namespace std;

vector<int> pai;

double distancia(pair<double,double> &a, pair<double,double> &b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int achar(int x) {
    // encontra o pai lider ("raiz") do conjunto
    if (pai[x] != x) {
        pai[x] = achar(pai[x]);
    }
    return pai[x];
}

bool unir(int x, int y) {
    // achar os lideres
    int achouX = achar(x);
    int achouY = achar(y);

    // se os dois pertence no mesmo grupo -> nao precisa unir
    if (achouX == achouY) return false;

    pai[achouY] = achouX;
    return true;
} 

int main() {
    int casos;
    cin >> casos;
    cin.ignore();
    cin.ignore();

    for (int c = 0; c < casos; c++) {
        if(c > 0) cout << endl;

        int qnt;
        cin >> qnt;

        vector<pair<double, double>> pontos;
        for (int i = 0; i < qnt; i++) {
            double x, y;
            cin >> x >> y;
            pontos.push_back(make_pair(x,y));
        }

        vector<tuple<int, int, double>> arestas;
        for (int i = 0; i < qnt; i++) {
            for (int j = i+1; j < qnt; j++) {
                arestas.push_back({i, j, distancia(pontos[i], pontos[j])});
            }
        }

        sort(arestas.begin(), arestas.end(), [](const tuple<int,int,double> &a, const tuple<int,int,double> &b) {
            return get<2>(a) < get<2>(b); // compara pela distancia
        });

        pai.resize(qnt);
        for (int i = 0; i < qnt; i++) {
            pai[i] = i; //cada elemento começa em seu proprio conjunto
        }

        double mst = 0;
        for (auto [x, y, dist] : arestas) {
            if (unir(x, y)) {
                mst += dist;
            }
        }
        cout << fixed << setprecision(2) << mst << endl;
        
    }
}