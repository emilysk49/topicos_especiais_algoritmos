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

int main() {
    int qntR;
    cin >> qntR;

    for (int r = 1; r <= qntR; r++) {
        int qntPont, qntArv; 
        cin >> qntPont >> qntArv;
        
        vector<double> x(qntPont);
        vector<double> y(qntPont);
        for (int i = 0; i < qntPont; i++) {
            cin >> x[i] >> y[i];
        }

        vector<double> tam_seg(qntPont-1);
        double tam_total = 0;

        // Calculo de cada segmento
        for(int i = 0; i < qntPont-1; i++) {
            tam_seg[i] = hypot(x[i+1]-x[i], y[i+1]-y[i]);
            tam_total += tam_seg[i];
        }

        // Distancia entre arvores
        double d = tam_total / (qntArv-1);

        cout << "Road #" << r << ":" << endl;

        int seg_idx = 0;
        double seg_restante = tam_seg[0]; // quanto resta do segmento
        double pos_seg = 0; // posição dentro do segmento
        cout << fixed << setprecision(2) << x[0] << " " << y[0] << endl; // primeira arvore

        for (int t = 1; t < qntArv-1; t++) {
            double distancia_restante = d;

            // Avanca pelos segmentos ate colocar a arvore
            while (distancia_restante > seg_restante) {
                distancia_restante -= seg_restante;
                seg_idx++;
                pos_seg = 0;
                seg_restante = tam_seg[seg_idx];
            }

            pos_seg += distancia_restante;
            // Interpolação linear
            double X = x[seg_idx] + (x[seg_idx+1]-x[seg_idx]) * (pos_seg / tam_seg[seg_idx]);
            double Y = y[seg_idx] + (y[seg_idx+1]-y[seg_idx]) * (pos_seg / tam_seg[seg_idx]);
            cout << X << " " << Y << endl;

            seg_restante -= distancia_restante;
        }

        // Última árvore no ponto final
        cout << x[qntPont-1] << " " << y[qntPont-1] << endl;

        cout << endl;

    }

}