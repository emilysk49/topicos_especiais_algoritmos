#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int qntLivros, qntDinheiro;
    vector<int> livros;

    while (cin >> qntLivros) {
        livros.clear();

        int livro;
        for (int i = 0; i < qntLivros; i++) {
            cin >> livro;
            livros.push_back(livro);
        }
        cin >> qntDinheiro;
        sort(livros.begin(), livros.end());

        int inicio = 0;
        int fim = qntLivros - 1;
        bool achou = false;
        int menori = 0;
        int menorj = 0;

        while (inicio < fim) {
            int soma = livros[inicio] + livros[fim];
            if (soma == qntDinheiro) {
                if (!achou || (livros[fim] - livros[inicio] < menorj - menori)) {
                    menori = livros[inicio];
                    menorj = livros[fim];
                    achou = true;
                }
                    
            }
            // soma > total de dinheiro -> diminui o fim
            if (soma > qntDinheiro) {
                fim--;
            } else { //soma < total de dinheiro -> aumenta o incio
                inicio++;
            }
        }

        cout << "Peter should buy books whose prices are " << menori << " and " << menorj << "." << endl;
        cout << endl;
    }
}