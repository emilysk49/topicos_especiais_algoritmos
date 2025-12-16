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

long long trianguloCont(vector<pair<long long, long long>> &P) {
    int n = P.size();
    long long contagem = 0;

    for (int i = 0; i < n; i++) {
        vector<long long> dist;
        dist.reserve(n - 1);

        long long x1 = P[i].first;
        long long y1 = P[i].second;

        // Distancias ao quadrado para todos os outros pontos
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            long long dx = x1 - P[j].first;
            long long dy = y1 - P[j].second;
            long long d2 = dx * dx + dy * dy;

            dist.push_back(d2);
        }

        // Ordena para agrupar distancias iguais
        sort(dist.begin(), dist.end());

        // Conta pares com mesma distância
        long long count = 1;
        for (int k = 1; k < dist.size(); k++) {
            if (dist[k] == dist[k - 1]) {
                count++;
            } else {
                contagem += (count * (count - 1)) / 2;
                count = 1;
            }
        }
        // Último grupo
        contagem += (count * (count - 1)) / 2;
    }

    return contagem;
   
}

int main() {
    while (true) {
        int qnt;
        cin >> qnt;
        if (qnt == 0) break;

        vector<pair<long long, long long>> pontos(qnt);
        for (int i = 0; i < qnt; i++) {
            cin >> pontos[i].first >> pontos[i].second;
        }

        cout << trianguloCont(pontos) << endl;
    }
}