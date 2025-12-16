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
    int qnt;
    int coluna, linha;
    cin >> linha >> coluna;

    qnt = linha * coluna;

    grafo.assign(qnt, vector<int>());
    contador = 0;

    vector<vector<int>> matriz(linha, vector<int>(coluna, -1));
    int no = 0;

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            char entrada;
            cin >> entrada;
            if (entrada == '#') {
                matriz[i][j] = no;
                if (i > 0 && matriz[i-1][j] != -1) {
                    int cima = matriz[i-1][j];
                    grafo[cima].push_back(no);
                    grafo[no].push_back(cima);
                }
                if (j > 0 && matriz[i][j-1] != -1) {
                    int esq = matriz[i][j-1];
                    grafo[esq].push_back(no);
                    grafo[no].push_back(esq);
                }
                no++;
            }
        }
    }

    ordemVisita.resize(no);
    menorTempo.resize(no);
    pai.assign(no, -1);
    ehArtic.assign(no, false);

    visitado.assign(no, false);
    for (int i = 0; i < no; i++) {
        if (!visitado[i]) dfs(i);
    }

    int count = 0;
    for (int i = 0; i < no; i++) {
        if (ehArtic[i]) count++;
    }

    if (no < 3) {
        cout << -1 << endl;
    } else if (count > 0) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}