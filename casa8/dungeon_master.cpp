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

int niveis, linhas, colunas;
int dungeon[30][30][30];
int dNivel[6] = {0, 0, 0, 0, -1, 1};
int dLinha[6] = {-1, 1, 0, 0, 0, 0};
int dColuna[6] = {0, 0, -1, 1, 0, 0};

int bfs(int sn, int sl, int sc, int en, int el, int ec) {
    queue<tuple<int,int,int>> fila;
    fila.push({sn, sl, sc}); //coloca posicoes de S
    int dist[30][30][30];
    memset(dist, -1, sizeof(dist));
    dist[sn][sl][sc] = 0;
    

    while(!fila.empty()) {
        auto [n,l,c] = fila.front(); 
        fila.pop();
        if (n == en && l == el && c == ec) return dist[n][l][c];

        for (int i = 0; i < 6; i++) {
            int newN = n + dNivel[i];
            int newL = l + dLinha[i];
            int newC = c + dColuna[i];

            if (newN >= 0 && newN < niveis && newL >= 0 && newL < linhas && newC >= 0 && newC < colunas) {
                if (dungeon[newN][newL][newC] == 1 && dist[newN][newL][newC] == -1) {
                    dist[newN][newL][newC] = dist[n][l][c] + 1;
                    fila.push({newN,newL,newC});
                }
            }
        }
    }
    return -1;
}


int main() {
    
    while (true) {
        cin >> niveis >> linhas >> colunas;
        if (niveis == 0 && linhas == 0 && colunas == 0) break;

        int SN, SL, SC;
        int EN, EL, EC;

        for (int n = 0; n < niveis; n++) {
            for (int l = 0; l < linhas; l++) {
                for (int c = 0; c < colunas; c++) {
                    char entrada;
                    cin >> entrada;
                    if (entrada == 'S') {
                        SN = n;
                        SL = l;
                        SC = c;
                        dungeon[n][l][c] = 1;
                    } else if (entrada == 'E') {
                        EN = n;
                        EL = l;
                        EC = c;
                        dungeon[n][l][c] = 1;
                    } else if (entrada == '#') {
                        dungeon[n][l][c] = 0;
                    } else if (entrada == '.') {
                        dungeon[n][l][c] = 1;
                    }
                }
            }
            string branco;
            getline(cin, branco); // linha em branco entre níveis
        }

        int minutos = bfs(SN, SL, SC, EN, EL, EC);

        if (minutos >= 0) {
            cout << "Escaped in " << minutos << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
    }
}