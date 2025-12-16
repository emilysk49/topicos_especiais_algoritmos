#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <iomanip>

using namespace std;

double pow_limit(double base, int exp) {
    double result = 1.0;
    while(exp > 0) {
        if(exp & 1) {
            result *= base;
            if(result > 1e9) result = 1e9; // limitar
        }
        base *= base;
        if(base > 1e9) base = 1e9;       // limitar
        exp >>= 1;
    }
    return result;
}

double npv(const vector<int>& CF, double r) {
    double total = 0.0;
    int T = CF.size() - 1;
    for(int i = 0; i <= T; i++) {
        total += CF[i] / pow_limit(1 + r, i);
    }
    return total;
}

double acharIRR(const vector<int>& CF) {
    double menor = -0.999999, maior = 1e9;
    double limite = 1e-9;

    // se NPV no maior for negativo, nao existe solucao
    // if(npv(CF, maior) < 0) return -1; // indica "No"

    while(maior - menor > limite) {
        double medio = (menor + maior) / 2.0;
        double val = npv(CF, medio);
        if(val > 0) menor = medio;
        else maior = medio;
    }
    return (menor + maior) / 2.0;
}


int main() {
    while(true) {
        int T;
        cin >> T;
        if(T == 0) break;

        vector<int> CF(T + 1);
        for(int i = 0; i <= T; i++) {
            cin >> CF[i];
        }

        double irr = acharIRR(CF);
        if(irr < -0.999) {
            cout << "No" << endl;
        } else {
            // imprime ate 2 casas decimais 
            cout << fixed << setprecision(2) << irr << endl;
        }
    }
    return 0;
}