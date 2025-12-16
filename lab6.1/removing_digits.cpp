#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x > 0) {
            int digito = x%10;
            x /= 10;
            if (digito > 0) {
                dp[i] = min(dp[i], dp[i - digito] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}