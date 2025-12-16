#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int qntPizza, preco;
    cin >> qntPizza;

    vector<int> precos(qntPizza*2);
    
    for (int i = 0; i < qntPizza*2; i++) {
        cin >> precos[i];
    }
    sort(precos.begin(), precos.end());

    int contagem = 0;
    for (int p = 0; p < qntPizza*2; p++) {
        if (p % 2) {
            contagem += precos[p];
        }
    }

    cout << contagem << endl;

}