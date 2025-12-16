#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <iomanip>

using namespace std;

long long determine(int i, int j, int n, vector<vector<long long>>& matrizA) {
    if (matrizA[i][j] != -1) return matrizA[i][j]; // já calculado

    long long res = 0;

    if (i < j) {
        // caso i < j: dividir intervalos
        long long maiorValor = 0;
        for (int k = i; k < j; k++) {
            maiorValor = max(maiorValor, determine(i,k,n,matrizA) + determine(k+1,j,n,matrizA));
        }
        res = maiorValor;

    } else {
        // caso i >= j: usar max1 + max2
        long long maior1 = 0;
        if (i < n) {
            for (int k = i + 1; k <= n; k++) {
                maior1 = max(maior1, determine(k,1,n,matrizA) + determine(k,j,n,matrizA));
            }
        }

        long long maior2 = 0;
        if (j > 0) {
            for (int k = 1; k < j; k++) {
                maior2 = max(maior2, determine(i,k,n,matrizA) + determine(n,k,n,matrizA));
            }
        }
        res = maior1 + maior2;
    }
    matrizA[i][j] = res;
    return res;
}

int main() {
    int n, an1;
    while (cin >> n >> an1) {
        vector<vector<long long>> matrizA(n+1, vector<long long>(n+1, -1));
        matrizA[n][1] = an1;
        cout << determine(1,n,n,matrizA) << endl;
    }
}