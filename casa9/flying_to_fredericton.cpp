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

const long long INF = 1e15;

int main() {
    int casos;
    cin >> casos;
    string branco;
    getline(cin, branco); // ler a linha em branco

    for(int c = 1; c <= casos; c++) {
        if (c > 1) cout << endl; // linha em branco entre cenários

        int cid;
        cin >> cid;
        getline(cin, branco); // ler o '\n'

        vector<string> cidades(cid);
        unordered_map<string,int> cidadeMap;
        for (int i = 0; i < cid; i++) {
            getline(cin, cidades[i]);
            cidadeMap[cidades[i]] = i;
        }

        int voos;
        cin >> voos;
        getline(cin, branco);

        vector<vector<pair<int,long long>>> grafo(cid); // grafo[u] = lista {v,custo}
        for (int i = 0; i < voos; i++) {
            string origem, destino;
            long long custo;
            cin >> origem >> destino >> custo;
            getline(cin, branco);
            int u = cidadeMap[origem];
            int v = cidadeMap[destino];
            grafo[u].push_back({v,custo});
        }

        int consul;
        cin >> consul;
        vector<int> consultas(consul);
        for (int i = 0; i < consul; i++) {
            cin >> consultas[i];
        }

        cout << "Scenario #" << c << endl;

        for (int q = 0; q < consul; q++) {
            int maximaParada = consultas[q];

            // dist[i][k] = custo minimo para chegar a cidade i com ate k voos
            vector<vector<long long>> dist(cid, vector<long long>(maximaParada+2, INF));
            dist[0][0] = 0; // Calgary

            for (int k = 0; k <= maximaParada; k++) {
                for (int u = 0; u < cid; u++) {
                    if (dist[u][k] < INF) {
                        for (auto p : grafo[u]) {
                            int v = p.first;
                            long long custo = p.second;
                            if (dist[v][k+1] > dist[u][k] + custo) {
                                dist[v][k+1] = dist[u][k] + custo;
                            }
                        }
                    }
                }
            }

            // procurar custo mínimo para Fredericton com ate maxStops+1 voos
            long long resposta = INF;
            for (int k = 1; k <= maximaParada+1; k++) {
                resposta = min(resposta, dist[cid-1][k]);
            }

            if (resposta == INF) {
                cout << "No satisfactory flights" << endl;
            } else {
                cout << "Total cost of flight(s) is $" << resposta << endl;
            }
        }
    }
}