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

// Soma dos dígitos de um número
int somaDigito(long long x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

// Verifica se é primo
bool ehPrimo(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

// Soma dos dígitos dos fatores primos
int somaPrimoFator(long long n) {
    int total = 0;

    // Conta fatores 2
    while (n % 2 == 0) {
        total += somaDigito(2);
        n /= 2;
    }

    // Fatores ímpares
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            total += somaDigito(i);
            n /= i;
        }
    }

    // Se sobrou um primo > 1
    if (n > 1)
        total += somaDigito(n);

    return total;
}

bool ehSmith(long long n) {
    if (ehPrimo(n)) return false;
    return somaDigito(n) == somaPrimoFator(n);
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        long long n;
        cin >> n;

        long long x = n+1;
        while (!ehSmith(x)) {
            x++;
        }

        cout << x << endl;
    }
}
