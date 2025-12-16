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
    string conta;
    int certos = 0;
    while (getline(cin, conta)) {
        
        int a, b, c;
        int indiceOp = conta.find('+');
        if (indiceOp == -1) indiceOp = conta.find('-');

        int indiceIgual = conta.find('=');

        char operacao = conta[indiceOp];
        
        a = stoi(conta.substr(0, indiceOp));
        b = stoi(conta.substr(indiceOp+1, indiceIgual - indiceOp - 1));
        string resp = conta.substr(indiceIgual + 1);

        if (resp == "?") continue;
        c = stoi(resp);

        if (operacao == '+' && a + b == c) {
            certos++;
        } else if (operacao == '-' && a - b == c) {
            certos++;
        }
    }

    cout << certos << endl;
}