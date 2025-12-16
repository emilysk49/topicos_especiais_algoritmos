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

const int MAXN = 20000000; // limite superior conhecido
vector<bool> ehPrimo(MAXN+1, true);
vector<pair<int,int>> parPrimos;

void crivo() {
    ehPrimo[0] = ehPrimo[1] = false;
    // Percorre todos os numeros de 2 ate √MAXN.
    for (int i = 2; i*i <= MAXN; i++) {
        // Se i ainda eh primo, marca todos os multiplos de i como n primos.
        if (ehPrimo[i]) {
            for (int j = i*i; j <= MAXN; j += i)
                ehPrimo[j] = false;
        }
    }

    // Encontrar pares de twin primes
    for (int i = 2; i+2 <= MAXN; i++) {
        // Se i e i+2 são primos, encontra um par e adiciona na lista
        if (ehPrimo[i] && ehPrimo[i+2])
            parPrimos.push_back({i, i+2});
    }
}

int main() {
    crivo(); // pré-cálculo

    int S;
    while (cin >> S) {
        // acessar par (índice S-1)
        auto p = parPrimos[S-1];
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
}