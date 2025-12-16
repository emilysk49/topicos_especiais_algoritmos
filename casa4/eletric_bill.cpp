#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

long long valor(long long consumo) {
    if (consumo <= 100) {
        return consumo * 2; // 1 a 100 -> 2
    } else if (consumo <= 10000) {
        return 200 + (consumo - 100) * 3; // 101 a 10000 -> 3
    } else if (consumo <= 1000000) {
        return 29900 + (consumo - 10000) * 5; // 10001 a 1000000 -> 5
    } else {
        return 4979900 + (consumo - 1000000) * 7; // > 1000001 -> 7
    }
}

long long buscaBinaria(long long baixo, long long alto, long long alvo) {
    long long resp;

    while (baixo <= alto) {
        long long medio = (baixo + alto) / 2;
        long long v = valor(medio);

        if (v <= alvo) {            
            resp = medio;       
            baixo = medio + 1;    
        } else {
            alto = medio - 1;
        }
    }
    return resp;
}

int main() {
    long long a, b;

    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        long long consumoT = buscaBinaria(0, 1000000000, a);
        long long menor = 0;
        long long maior = consumoT/2;
        long long consumoM = -1;

        // chegar no valor x sabendo que x + y = consumoT e |x - y| = b
        while (menor <= maior) {
            long long medio = (menor + maior) / 2;
            // diferenca entre valor do medio (x) e consumoT - medio (y)
            long long diferenca = llabs(valor(consumoT - medio) - valor(medio));

            if (diferenca == b) {
                consumoM = min(medio, consumoT - medio);
                break;
            }
            
            if (diferenca > b) {
                menor = medio + 1;
            } else {
                maior = medio - 1;
            }
        }

        if (consumoM < 0) {
            consumoM = menor;
        }

        cout << valor(consumoM) << endl;
    }
}