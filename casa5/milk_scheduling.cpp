#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    vector<pair<int,int>> fila;
    int n;
    cin >> n;

    int leite, deadline;
    for (int i = 0; i < n; i++) {
        cin >> leite >> deadline;
        fila.push_back({deadline, leite});
    }
    sort(fila.begin(), fila.end());

    vector<int> ordenando;
    for (auto &vaca : fila) {
        // coloca no vetor quantidade de leite
        ordenando.push_back(vaca.second);
        // se quantidade de vaca maior que deadline 
        if (ordenando.size() > vaca.first) {
            // pega o que menos cria leite
            auto it = min_element(ordenando.begin(), ordenando.end());
            // e apaga
            ordenando.erase(it);
        }
    }
    int leiteTotal = 0;
    for (int v : ordenando) leiteTotal += v;
    cout << leiteTotal << endl;
}