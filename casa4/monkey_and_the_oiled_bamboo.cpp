#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;
vector<int> degraus;

bool testar(int k) {
    int anterior = 0;
    int forca = k;
    for (int d : degraus) {
        // se diferenca de degrau for maior que forca -> nao deu
        if ((d - anterior) > forca) return false;
        if ((d - anterior) == forca) forca--;
        anterior = d;
    }
    return true;
}

int buscaBinaria(int baixo, int alto) {
    if (baixo == alto) {
        return baixo;
    }

    int medio = (baixo + alto) / 2;
    
    if (testar(medio)) {
        // se deu certo testa com novo intervalo menor
        return buscaBinaria(baixo, medio);
    } else {
        // se deu errado testa com novo intervalo maior 
        return buscaBinaria(medio + 1, alto);
    }
}

int main() {
    int casos, qntDegraus;

    cin >> casos;

    for (int c = 0; c < casos; c++) {
        cin >> qntDegraus;
        degraus.clear();
        degraus.resize(qntDegraus);
        int menor;
        for (int d = 0; d < qntDegraus; d++) {
            cin >> degraus[d];
            // menor salto : maior diferenca entre degraus
            if (d == 1 || menor < (degraus[d-1] - degraus[d])) {
                menor = degraus[d-1] - degraus[d];
            }
        }
        // maior salto : maior degrau
        int maior = degraus[qntDegraus-1];
        int k = buscaBinaria(menor, maior);
        cout << "Case " << c+1 << ": " << k << endl;
    }
}