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

vector<pair<double, double>> coordendadas;
const double INF = 1e9;

double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
    int caso = 1;
    while (true) {
        int pedras;
        cin >> pedras;
        if (pedras == 0) break;
        coordendadas.clear();
        vector<vector<double>> dist(pedras, vector<double>(pedras));

        for (int i = 0; i < pedras; i++) {
            double x, y;
            cin >> x >> y;
            if (i > 0) {
                for (int j = 0; j < coordendadas.size(); j++) {
                    double d = distancia(coordendadas[j].first, coordendadas[j].second, x, y);
                    dist[i][j] = d;
                    dist[j][i] = d;
                }
            }
            coordendadas.push_back({x, y});
        }

        vector<double> custo(pedras, INF);
        vector<bool> visitado(pedras, false);

        custo[0] = 0.0;

        for (int i = 0; i < pedras; i++) {
            int u = -1;
            double menor = INF;
            for (int j = 0; j < pedras; j++) {
                // se j nao for visitado e custo ate j for menor que o menor atual
                if (!visitado[j] && custo[j] < menor) {
                    menor = custo[j];
                    u = j;
                }
            }
            if (u == -1) break;
            visitado[u] = true;

            // para cada vizinho de u
            for (int v = 0; v < pedras; v++) {
                // se nao foi visitado
                if (!visitado[v]) {
                    // maior valor entre : maior salto ate u ou alto direto de u -> v
                    double novoC = max(custo[u], dist[u][v]);
                    if (novoC < custo[v]) {
                        custo[v] = novoC;
                    }
                }
            }
        }

        cout << "Scenario #" << caso++ << "\n";
        cout << fixed << setprecision(3);
        cout << "Frog Distance = " << custo[1] << "\n\n";
    }
}