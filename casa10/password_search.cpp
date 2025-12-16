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

int main() {
    int tam;
    string mensagem;
    while (cin >> tam >> mensagem) {
        unordered_map<string, int> freq;
        for (int i = 0; i <= mensagem.size() - tam; i++) {
            string pedaco = mensagem.substr(i, tam);
            freq[pedaco]++;
        }

        string senha;
        int maior = 0;
        for (auto &p : freq) {
            if (p.second > maior) {
                maior = p.second;
                senha = p.first;
            }
        }

        cout << senha << endl;
    }
}