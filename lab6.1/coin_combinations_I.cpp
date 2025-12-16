#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>

using namespace std;

int main() {
    long long n, soma;

    cin >> n >> soma;

    vector<long long> moedas(n);
    vector<long long> dp(soma+1);

    for (long long i = 0; i < n; i++) {
        cin >> moedas[i];
    }

    dp[0] = 1;
    for (long long j = 1; j < soma; j++) {
        dp[j] = 0;
    }
    
    for (long long i = 1; i <= soma; i++) {
        for (long long m = 0; m < n; m++) {
            if (i >= moedas[m]) {
                dp[i] += dp[i - moedas[m]];
                dp[i] = dp[i] % 1000000007;
            }
        }
    }
    cout << dp[soma] << endl;
}