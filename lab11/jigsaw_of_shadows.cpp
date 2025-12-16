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

double sombra(int angulo, int altura) {
    double radiano = (3.141592653589793238462*(double)angulo)/180.0;
    return (double)altura/tan(radiano);
}

int main() {
    int angulo, qnt;
    cin >> angulo >> qnt;

    vector<pair<int, int>> pessoas(qnt);
    for (int p = 0; p < qnt; p++) {
        cin >> pessoas[p].first >> pessoas[p].second;
    }

    sort(pessoas.begin(), pessoas.end());
    double distancia = 0.0;
    double antes = 0.0;

    for (int i = 0; i < qnt; i++) {
        double d = sombra(angulo, pessoas[i].second);
        if (((double)pessoas[i].first + d) <= antes) {
            continue;
        } else if ((double)pessoas[i].first < antes) {
            double dif = antes - (double)pessoas[i].first;
            distancia -= dif;
        }
        distancia += d;
        antes = (double)pessoas[i].first + d;
    }

    cout << fixed << setprecision(14) << distancia << endl;
}