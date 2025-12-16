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
    string text;
    while (getline(cin, text)) {
        string letras = "";
        for (char carac : text) {
            if (isupper(carac)) letras += carac;
        }

        int n = letras.size();
        for (int L = 1; L <= n; L++) {
            unordered_map<string, int> freq;
            freq.reserve(n); // otimização
            int maior = 0;

            for (int i = 0; i + L <= n; i++) {
                string sub = letras.substr(i, L);
                int f = ++freq[sub];
                maior = max(maior, f);
            }

            if (maior < 2) {
                cout << "\n";
                break;
            } else {
                cout << maior << "\n";
            }
        }
    }
}