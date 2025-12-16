#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <unordered_map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int tamS = s.size();
    int tamT = t.size();

    //matriz de tamanho s+1 x t+1
    vector<vector<int>> dp(tamS+1, vector<int>(tamT+1, 0));

    // s = axyb
    // t = abyxb
    for (int indS = 1; indS <= tamS; indS++) {
        for (int indT = 1; indT <= tamT; indT++) {
            if (s[indS-1] == t[indT-1]) { // se caracter igual
                dp[indS][indT] = dp[indS-1][indT-1] + 1; // valor seria o anterior + 1
            } else {
                // descarta o ultimo caracter de s ou t 
                if (dp[indS-1][indT] > dp[indS][indT-1]) { 
                    dp[indS][indT] = dp[indS-1][indT];
                } else {
                    dp[indS][indT] = dp[indS][indT-1];
                }
            }
        }
    }

    // reconstruir
    string lcs = "";
    int i = tamS, j = tamT;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]); // faz parte da LCS
            i--; j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--; // vem de cima
        } else {
            j--; // vem da esquerda
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;

}