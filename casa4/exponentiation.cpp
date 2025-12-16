#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

const long long MOD = 1000000007LL;

long long potencia(long long a, long long b, long long mod) {
    a = a % mod;
    long long resposta = 1;
    while (b > 0) {
        if (b & 1) { //se b eh impar (..XXX1 & ..0001)
            resposta = resposta * a % mod;
        }
        a = a * a % mod; // eleva ao quadrado
        b = b >> 1; // divide expoente por 2
    }
    return resposta;

}

int main() {
    int testes;
    long long a, b;
    cin >> testes;

    for (int i = 0; i < testes; i++) {
        cin >> a >> b;
        long long resposta = potencia(a,b,MOD);
        cout << resposta << endl;
    }
}