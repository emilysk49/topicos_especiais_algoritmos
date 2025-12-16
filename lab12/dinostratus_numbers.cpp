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

const int MAXN = 1048576; // limite superior conhecido
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
}

bool fatorar(long long n) {
    map<long long, int> fatores;
    for (long long p = 2; p <= n; p++) {
        if (ehPrimo[p]) {
            while (n % p == 0) {
                n /= p;
                fatores[p]++;
                if (fatores[p] >= 8) {
                    return true;
                } else if (fatores.size() >= 4) {
                    return true;
                } else if (fatores.size() == 2) {
                    int inicio = 0;
                    for (auto x : fatores) {
                        if (inicio == 0) {
                            inicio = x.second;
                        } else if (inicio == 1 && x.second >= 5) {
                            return true;
                        } else if (inicio >= 2 && x.second >= 2) {
                            return true;
                        } else if (inicio >= 5 && x.second >= 1) {
                            return true;
                        }
                    }
                } else if (fatores.size() == 3) {
                    for (auto x : fatores) {
                        if (x.second >= 2) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    crivo();
    int caso = 1;

    int S;
    while (cin >> S) {
        bool sim = fatorar(S);
        cout << "Instance " << caso++ << endl;
        if (sim) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}