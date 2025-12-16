#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int linhas, colunas;
vector<vector<int>> grafo;
// direcoes: 0 = north, 1 = east, 2 = south, 3 = west
int dLinha[4] = {-1, 0, 1, 0};
int dColuna[4] = {0, 1, 0, -1};

int bfs(int s1, int s2, int e1, int e2, int inicioDir) {

    queue<tuple<int,int,int,int>> fila; // linha, coluna, direcao, tempo
    vector<vector<vector<bool>>> visitado(linhas+1, vector<vector<bool>>(colunas+1, vector<bool>(4, false)));

    fila.push({s1, s2, inicioDir, 0});
    visitado[s1][s2][inicioDir] = true;

    while (!fila.empty()) {
        auto [l, c, dir, tempo] = fila.front(); 
        fila.pop();

        if(l == e1 && c == e2) {
            return tempo;
        }

        // tentar Go -> seguir 1, 2, 3
        for (int m = 1; m < 4; m++) {
            int newLinha = l + dLinha[dir] * m;
            int newColuna = c + dColuna[dir] * m;
            bool go = true;

            // vai avancando e verificando 
            for (int passo = 1; passo <= m; passo++) {
                int avancaL = l + dLinha[dir] * passo;
                int avancaC = c + dColuna[dir] * passo;

                // verfica se ta fora do limite e se tem obstaculo ao redor 
                if (avancaL <= 0 || avancaC <= 0 || avancaL >= linhas || avancaC >= colunas) {
                    go = false;
                    break;
                }

                if (grafo[avancaL][avancaC] == 1 ||
                    (grafo[avancaL-1][avancaC] == 1) ||
                    (grafo[avancaL][avancaC-1] == 1) ||
                    (grafo[avancaL-1][avancaC-1] == 1)) {
                    go = false;
                    break;
                }
            }

            // se eh possivel avancar com GO e lugar nao foi visitado
            if (go && !visitado[newLinha][newColuna][dir]) {
                visitado[newLinha][newColuna][dir] = true;
                fila.push({newLinha, newColuna, dir, tempo+1});
            }
        }

        // tentar turn direita / esquerda
        for (int turn = -1; turn <= 1; turn += 2) {
            int newDir = (dir + turn + 4) % 4;
            if (!visitado[l][c][newDir]) {
                visitado[l][c][newDir] = true;
                fila.push({l, c, newDir, tempo+1});
            }
        }
    }

    return -1;
}

int dirInt(string dir) {
    if (dir == "north") return 0;
    if (dir == "east") return 1;
    if (dir == "south") return 2;
    if (dir == "west") return 3;
    return -1;
}

int main() {

    while (true) {
        cin >> linhas >> colunas;
        if (linhas == 0 && colunas == 0) break;

        grafo.assign(linhas, vector<int>(colunas, -1));

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cin >> grafo[i][j];
            }
        }
        int si, sj, ei, ej;
        string inicioDir;
        cin >> si >> sj >> ei >> ej >> inicioDir;
        int sd = dirInt(inicioDir);

        int resp = bfs(si, sj, ei, ej, sd);

        cout << resp << endl;
    }
}