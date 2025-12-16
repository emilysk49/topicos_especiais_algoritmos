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

    for (int i = 0; i < casos; i++) {
        int elefantes, limite;
        cin >> elefantes >> limite;
        vector<int> lista(elefantes);
        for (int e = 0; e < elefantes; e++) {
            cin >> lista[e];
        }
        sort(lista.begin(), lista.end());
        int peso = 0;
        int contagem = 0;
        for (int n : lista) {
            if (peso + n <= limite) {
                peso += n;
                contagem++;
            } else {
                break;
            }
        }
        cout << contagem << endl;
    }
}
