#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int qntBalao;
    int qntFlechas = 0;
    cin >> qntBalao;

    int flechas[1000002] = {0};

    for (int i = 0; i < qntBalao; i++) {
        int altura;
        cin >> altura;

        if (flechas[altura+1] > 0) {
            flechas[altura+1]--;
            flechas[altura]++;
        } else {
            qntFlechas++;
            flechas[altura]++;
        }
    }
    cout << qntFlechas << endl;
}