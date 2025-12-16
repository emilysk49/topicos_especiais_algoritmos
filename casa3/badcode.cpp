#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

vector<string> resultados;
map<int,char> codigo;


void backtracking(string cripto, string atual, int indice) {
    // se chegou no limite
    // if (resultados.size() >= 100) return;

    // se achou todos codigos
    if (indice == cripto.size()) {
        resultados.push_back(atual);
        return;
    }

    string num_string = "";
    for (int i = indice; i < cripto.size(); i++) {
        num_string += cripto[i];
        int num = stoi(num_string); // trasforma em int "0001" -> 1

        if (num == 0) continue; //enquanto 0's avança
        
        if (num > 99) break; // se chegar no limite sai

        if (codigo.count(num)) {
            backtracking(cripto, atual + codigo[num], i+1);
        }
    }

}

int main() {
    int quantidade;
    int caso = 1;
    while (true) {
        cin >> quantidade;
        if (quantidade == 0) break;

        string cripto;
        resultados.clear();
        codigo.clear();

        for (int i = 0; i < quantidade; i++) {
            char caracter;
            int cod;
            cin >> caracter >> cod;
            codigo[cod] = caracter;
        }

        cin >> cripto;
        backtracking(cripto, "", 0);
        sort(resultados.begin(), resultados.end());
        
        cout << "Case #" << caso << endl;
        caso++;

        int limite = min(100, (int)resultados.size());
        for (int i = 0; i < limite; i++) {
            cout << resultados[i] << endl;
        }
        cout << endl;
    }
    return 0;
}