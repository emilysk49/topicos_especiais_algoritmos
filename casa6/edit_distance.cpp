#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <unordered_map>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        string a, b;
        cin >> a >> b;

        int tamA = a.size();
        int tamB = b.size();
        vector<vector<int>> dp(tamA+1, vector<int>(tamB+1, 0));
        // Inicializa base cases
        for (int i = 0; i <= tamA; i++) dp[i][0] = i; // apagar todos os caracteres de A 
        for (int j = 0; j <= tamB; j++) dp[0][j] = j; // inserir todos os caracteres de B 


        for (int i = 1; i <= tamA; i++) {
            for (int j = 1; j <= tamB; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int apagar = dp[i-1][j] + 1;
                    int inserir = dp[i][j-1] + 1;
                    int substituir = dp[i-1][j-1] + 1;
                    dp[i][j] = min({apagar, inserir, substituir});
                }
            }
        }

        cout << dp[tamA][tamB] << endl;
    }
}