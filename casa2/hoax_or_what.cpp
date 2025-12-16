#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    while (true) {
        int dias;
        long long valor = 0;
        multiset<int> urna;
        cin >> dias;
        if (dias == 0) {
            break;
        }

        int quantidade;
        for (int i = 0; i < dias; i++) {
            cin >> quantidade;
            if (quantidade > 0) {
                for (int n = 0; n < quantidade; n++) {
                    int notas;
                    cin >> notas;
                    urna.insert(notas);
                }
            }
            if (!urna.empty()) {
                int maior = *prev(urna.end());
                int menor = *urna.begin();
                urna.erase(prev(urna.end()));
                urna.erase(urna.begin());

                valor += maior - menor;
            }
        }
        cout << valor << endl;
    }
}