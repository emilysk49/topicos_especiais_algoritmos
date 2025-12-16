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
        int num;
        int quantidade = 0;
        int pulos = 0;
        bool pular = false;
        cin >> num;
        for (int i = 0; i < num; i++) {
            char terreno;
            cin >> terreno;
            if (terreno == '.' && !pular) {
                quantidade++;
                pulos++;
                pular = true;
            } else if (pular && pulos == 2) {
                pular = false;
                pulos = 0;
            } else if (pular) {
                pulos++;
            }
        }
        cout << "Case " << c+1 << ": " << quantidade << endl;
    }
}