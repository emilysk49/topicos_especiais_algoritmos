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
    string linha, numero;

    while (getline(cin, linha)) {
        numero += linha; // concatena linhas ate encontrar '#'
        
        int pos;
        // enquanto tem "#" no string
        while ((pos = numero.find('#')) != string::npos) {
            string bin = numero.substr(0, pos); // pega o numero ate '#'
            int mod = 0;
            for (char c : bin) {
                if (c == '0' || c == '1') {
                    mod = (mod * 2 + (c - '0')) % 131071;
                }
            }
            if (mod == 0) cout << "YES" << endl;
            else cout << "NO" << endl;

            numero = numero.substr(pos + 1); // remove o número processado
        }
    }
    return 0;
}