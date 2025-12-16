#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <sstream>
#include <cstring>

using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
vector<int> ordemVisita; //disc -> momento que visitou no
vector<int> menorTempo; //low -> no mais antigo que pode alcancar sem usar o caminho usado para atual no
vector<int> pai;
vector<bool> ehArtic; 
int contador;

void dfs(int u) {
    visitado[u] = true;
    contador++;
    ordemVisita[u] = menorTempo[u] = contador;
    int filhos = 0;

    for (int v : grafo[u]) {
        if (!visitado[v]) {
            filhos++;
            //marca u como pai de v
            pai[v] = u;
            dfs(v);

            // depois de visitar v e seus conectados
            // atualiza menorTempo baseado no no V
            // Qual no mais antigo que posso alcancar partir de u depois de explorar filho v?
            menorTempo[u] = min(menorTempo[u], menorTempo[v]);

            // filho v nao consegue alcancar nenhum ancestral de u sem passar por u -> critico
            if (pai[u] != -1 && menorTempo[v] >= ordemVisita[u]) ehArtic[u] = true;

        } else if (v != pai[u]) { // se v foi vistado e nao eh o pai
            // atualiza menorTempo de u com ordemVisita de v 
            // u consegue alcancar no antigo atras de outra rota (sem depender do pai)
            menorTempo[u] = min(menorTempo[u], ordemVisita[v]);
        }
    }

    // se eh no raiz e tem mais de um filho
    if (pai[u] == -1 && filhos > 1) {
        ehArtic[u] = true;
    }
}

int main() {
    while (true) {
        int qnt;
        cin >> qnt;
        if (qnt == 0) break;
        grafo.clear();
        ordemVisita.clear();
        menorTempo.clear();
        pai.clear();
        ehArtic.clear();
        grafo.assign(qnt+1, vector<int>());
        ordemVisita.resize(qnt+1);
        menorTempo.resize(qnt+1);
        pai.assign(qnt+1, -1);
        ehArtic.assign(qnt+1, false);
        contador = 0;

        string linha;
        while (true) {
            getline(cin, linha);
            if (linha == "0") break;
            stringstream ss(linha);
            int u;
            ss >> u;
            int v;
            while (ss >> v) {
                // bidirecional
                grafo[u].push_back(v);
                grafo[v].push_back(u);
            }
        }

        visitado.assign(qnt, false);
        for (int i = 1; i <= qnt; i++) {
            if (!visitado[i]) dfs(i);
        }

        int count = 0;
        for (int i = 1; i<= qnt; i++) {
            if (ehArtic[i]) count++;
        }
        cout << count << endl;
    }
}