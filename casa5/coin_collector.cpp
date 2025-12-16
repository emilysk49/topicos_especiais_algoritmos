#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int qntMoedas;
        cin >> qntMoedas;

        int moeda;
        long long alcance = 0;
        int quantidade = 0;
        long long anterior;
        cin >> anterior;

        for (int i = 1; i < qntMoedas; i++) {
            cin >> moeda;
            if (alcance + anterior < moeda) {
                alcance += anterior;
                quantidade++;
            }
            anterior = moeda;
        }
        quantidade++;
        cout << quantidade << endl;
    }
}