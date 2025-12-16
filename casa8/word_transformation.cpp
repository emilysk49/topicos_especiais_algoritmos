#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <queue>
#include <tuple>
#include <cstring>
#include <unordered_map>
#include <sstream>
#include <unordered_set>

using namespace std;

int bfs(unordered_map<string, vector<string>> &grafo, string &inicio, string &fim) {
    queue<pair<string,int>> fila;
    unordered_set<string> visitado;
    fila.push({inicio, 0});
    visitado.insert(inicio);

    while (!fila.empty()) {
        auto [palavra, passos] = fila.front(); 
        fila.pop();
        if (palavra == fim) return passos;

        for (auto &v : grafo[palavra]) {
            if (!visitado.count(v)) {
                visitado.insert(v);
                fila.push({v, passos+1});
            }
        }
    }
    return -1;
}

int main() {
    int casos;
    string palavra;
    cin >> casos;
    cin.ignore();
    getline(cin, palavra);
    
    for (int c = 0; c < casos; c++) {

        string pAnterior;
        vector<string> dicionario;
        unordered_map<string, vector<string>> grafo;
        while (getline(cin, palavra)) {
            //cout << "LENDO -----> " << palavra << endl;
            if (palavra == "*") break;
            dicionario.push_back(palavra);
        }

        int qnt = dicionario.size();
        for (int i = 0; i < qnt; i++) {
            for (int j = i+1; j < qnt; j++) {
                string a = dicionario[i];
                string b = dicionario[j];
                if (a.size() == b.size()) {
                    bool par = true;
                    int dif = 0;
                    for (int indice = 0; indice < a.size(); indice++) {
                        if (a[indice] != b[indice]) dif++;
                        if (dif > 1) {
                            par = false;
                            break;
                        }
                    }
                    if (par) {
                        grafo[a].push_back(b);
                        grafo[b].push_back(a);
                    }
                }
            }
        }

        string linha;
        while (getline(cin, linha)) {
            if (linha.empty()) break;
            stringstream ss(linha);
            string inicio, fim;
            ss >> inicio >> fim;
            int passos = bfs(grafo, inicio, fim);
            cout << inicio << " " << fim << " " << passos << endl;
        }
        if (c < casos - 1) cout << endl;
        
    }
}