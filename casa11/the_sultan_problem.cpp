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
double poligonoArea(const vector<pair<double,double>>& poli) {
    double area = 0;
    int n = poli.size();
    for(int i = 0; i < n; i++){
        int j = (i+1)%n;
        area += poli[i].first * poli[j].second - poli[j].first * poli[i].second;
    }
    return fabs(area)/2.0;
}

// Função ponto dentro de polígono 
bool dentroPoligono(pair<double,double> p, const vector<pair<double,double>>& poli) {
    int n = poli.size();
    bool dentro = false;
    for (int i = 0, j = n-1; i < n ; j = i++){
        auto pi = poli[i], pj = poli[j];
        if (((pi.second > p.second) != (pj.second > p.second)) && p.first < (pj.first - pi.first)*(p.second - pi.second)/(pj.second - pi.second) + pi.first)
            dentro = !dentro;
    }
    return dentro;
}

// lado do ponto em relação a linha
double lado(pair<double,double> p, pair<double,double> a, pair<double,double> b) {
    return (b.first - a.first)*(p.second - a.second) - (b.second - a.second)*(p.first - a.first);
}

// Cortar polígono, mantendo apenas lado >=0
vector<pair<double,double>> cortarPoligono(const vector<pair<double,double>>& poli, pair<double,double> a, pair<double,double> b) {
    vector<pair<double,double>> novo;
    int n = poli.size();
    for(int i = 0; i < n; i++){
        auto atual = poli[i];
        auto prox = poli[(i+1)%n];
        double lado_atual = lado(atual,a,b);
        double lado_prox = lado(prox,a,b);

        if(lado_atual >= 0) novo.push_back(atual);

        if(lado_atual * lado_prox < 0){
            double t = lado_atual / (lado_atual - lado_prox);
            pair<double,double> inter;
            inter.first = atual.first + t*(prox.first - atual.first);
            inter.second = atual.second + t*(prox.second - atual.second);
            novo.push_back(inter);
        }
    }
    return novo;
}


int main() {
    int caso = 1;
    int N, largura, altura;
    double x, y;

    while(cin >> N >> largura >> altura >> x >> y){
        vector<pair<double,double>> poli = {{0,0},{(double)largura,0},{(double)largura,(double)altura},{0,(double)altura}};

        for (int i = 0; i < N; i++){
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // Determinar lado da fonte
            double s = lado({x,y},{x1,y1},{x2,y2});
            if(s >= 0) {
                poli = cortarPoligono(poli,{x1,y1},{x2,y2});
            } else {
                poli = cortarPoligono(poli,{x2,y2},{x1,y1});
            }
        }

        double area = poligonoArea(poli);
        cout << "Case #" << caso++ << ": " << fixed << setprecision(3) << area << endl;
    }
    return 0;
}