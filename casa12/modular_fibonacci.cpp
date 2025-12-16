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

// Multiplicação de matrizes 2x2 módulo mod
void multiplicar(long long a[2][2], long long b[2][2], long long mod) {
    long long x = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod;
    long long y = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod;
    long long z = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
    long long w = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod;

    a[0][0] = x; a[0][1] = y;
    a[1][0] = z; a[1][1] = w;
}

// Exponenciação rápida de matriz
void exp_matriz(long long mat[2][2], long long n, long long mod) {
    // inicia com matriz de identidade
    long long res[2][2] = {{1,0},{0,1}};
    // mstriz inicial
    long long atual[2][2] = {{mat[0][0], mat[0][1]}, {mat[1][0], mat[1][1]}};
    
    while(n > 0) {
        // se o bit menos significativo de n for 1, multiplicamos res por atual
        if (n & 1) multiplicar(res, atual, mod);
        multiplicar(atual, atual, mod);
        //divide por 2
        n >>= 1;
    }
    mat[0][0] = res[0][0]; mat[0][1] = res[0][1];
    mat[1][0] = res[1][0]; mat[1][1] = res[1][1];
}

int main() {
    long long n, m;
    while(cin >> n >> m) {
        long long mod = 1 << m;
        if (n == 0) { 
            cout << 0 << endl; 
            continue; 
        }
        long long fib[2][2] = {{1,1},{1,0}};
        // eleva matriz fib a n-1 com mod
        exp_matriz(fib, n-1, mod);

        cout << fib[0][0] % mod << endl;
    }
    return 0;
}