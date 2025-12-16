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

// produto vetorial
// resp > 0 : anti-horario
// resp < 0 horario
// resp = 0 colineares
long long cross(const pair<long long,long long> &O, const pair<long long,long long> &A, const pair<long long,long long> &B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}


vector<pair<long long, long long>> convexHull(vector<pair<long long, long long>> &pts) {
    sort(pts.begin(), pts.end());
    vector<pair<long long, long long>> hull;
    
    // Parte inferior
    for (auto &p : pts) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }
    
    // Parte superior
    size_t t = hull.size() + 1;
    for (int i = (int)pts.size()-2; i >= 0; i--) {
        while (hull.size() >= t && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    
    hull.pop_back();
    return hull;
}

long long dist2(pair<long long, long long> &A, pair<long long, long long> &B) {
    long long dx = A.first - B.first;
    long long dy = A.second - B.second;
    return dx*dx + dy*dy;
}

long long maiorDist(vector<pair<long long, long long>> &hull) {
    int n = hull.size();
    if (n == 1) return 0;
    int j = 1;
    long long maxDist = 0;
    for (int i = 0; i < n; i++) {
        // Enquanto a area do paralelo formado aumentar, move j
        while (cross(hull[i], hull[(i+1)%n], hull[(j+1)%n]) > cross(hull[i], hull[(i+1)%n], hull[j])) {
            j = (j+1) % n;
        }
        // Atualiza a distancia maxima entre os pontos atuais
        maxDist = max(maxDist, dist2(hull[i], hull[j]));
        maxDist = max(maxDist, dist2(hull[(i+1)%n], hull[j]));
    }
    return maxDist;
}

int main() {
    int qnt;
    cin >> qnt;

    vector<pair<long long, long long>> pontos(qnt);
    for (int i = 0; i < qnt; i++) {
        cin >> pontos[i].first >> pontos[i].second;
    }

    vector<pair<long long, long long>> fecho = convexHull(pontos);
    long long maior = maiorDist(fecho);

    cout << fixed << setprecision(8) << sqrt((double)maior) << endl;
}