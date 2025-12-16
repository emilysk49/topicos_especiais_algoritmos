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
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

int dr[4] = {-1, 1, 0, 0}; // N, S, W, E
int dc[4] = {0, 0, -1, 1};
char dir_emp[4] = {'N', 'S', 'W', 'E'};
char dir_cam[4] = {'n', 's', 'w', 'e'};

int main() {
    int linha, coluna;
    int casos = 1;

    while (true) {
        cin >> linha >> coluna;
        if (linha == 0 || coluna == 0) break;

        vector<string> grafo(linha);
        for (int i = 0; i < linha; i++) cin >> grafo[i];

        int sx, sy, bx, by, tx, ty;
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                if (grafo[i][j] == 'S') sx = i, sy = j;
                if (grafo[i][j] == 'B') bx = i, by = j;
                if (grafo[i][j] == 'T') tx = i, ty = j;
            }
        }

        // visitado[bx][by][px][py]
        bool visitado[20][20][20][20] = {0};
        queue<tuple<int,int,int,int,string>> fila;
        fila.push({bx, by, sx, sy, ""});
        visitado[bx][by][sx][sy] = true;

        string resposta = "";
        bool achou = false;

        while (!fila.empty()) {
            auto [bx, by, px, py, caminho] = fila.front();
            fila.pop();

            if (bx == tx && by == ty) {
                resposta = caminho;
                achou = true;
                break;
            }

            // tenta empurrar em cada direção
            for (int d = 0; d < 4; d++) {
                int novoBx = bx + dr[d];
                int novoBy = by + dc[d]; // nova posição da caixa
                int jogadorX = bx - dr[d];
                int jogadorY = by - dc[d]; // posição onde jogador deve estar para empurrar

                // verifica se posições são validas
                if (novoBx < 0 || novoBx >= linha || novoBy < 0 || novoBy >= coluna) continue;
                if (jogadorX < 0 || jogadorX >= linha || jogadorY < 0 || jogadorY >= coluna) continue;
                if (grafo[novoBx][novoBy] == '#' || grafo[jogadorX][jogadorY] == '#') continue;

                // BFS interno: jogador vai ate jogadorX, jogadorY sem passar por paredes ou pela caixa
                queue<pair<int,int>> cam_fila;
                map<pair<int,int>, string> cam_path;
                bool jaVis[20][20] = {0};
                cam_fila.push({px, py});
                cam_path[{px, py}] = "";
                jaVis[px][py] = true;

                bool chegou = false;
                string camseq = "";

                while (!cam_fila.empty()) {
                    auto [x, y] = cam_fila.front();
                    cam_fila.pop();

                    if (x == jogadorX && y == jogadorY) {
                        chegou = true;
                        camseq = cam_path[{x, y}];
                        break;
                    }

                    for (int k = 0; k < 4; k++) {
                        int novoX = x + dr[k];
                        int novoY = y + dc[k];
                        if (novoX < 0 || novoX >= linha || novoY < 0 || novoY >= coluna) continue;
                        if (grafo[novoX][novoY] == '#') continue;
                        if (novoX == bx && novoY == by) continue; // não atravessa a caixa
                        if (jaVis[novoX][novoY]) continue;

                        jaVis[novoX][novoY] = true;
                        cam_path[{novoX, novoY}] = cam_path[{x, y}] + dir_cam[k];
                        cam_fila.push({novoX, novoY});
                    }
                }

                if (!chegou) continue;

                int novoJx = bx;
                int novoJy = by; // jogador fica onde estava a caixa após o push
                if (!visitado[novoBx][novoBy][novoJx][novoJy]) {
                    visitado[novoBx][novoBy][novoJx][novoJy] = true;
                    fila.push({novoBx, novoBy, novoJx, novoJy, caminho + camseq + dir_emp[d]});
                }
            }
        }

        cout << "Maze #" << casos++ << endl;

        if (achou) {
            cout << resposta << endl;
        } else {
            cout << "Impossible." << endl;
        }
        cout << endl;
    }
}