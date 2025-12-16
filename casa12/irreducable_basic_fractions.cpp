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

long long eulerPhi(long long n) {
    long long resultado = n;
    // percorre todos os números p de 2 até √n.
    for (long long p = 2; p * p <= n; ++p) {
        // se p é um fator de n , então p é um fator primo de n
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            resultado = resultado / p * (p - 1);
        }
    }
    if (n > 1) resultado = resultado / n * (n - 1);
    return resultado;
}

int main() {
    long long n;
    while (cin >> n && n != 0) {
        cout << eulerPhi(n) << endl;
    }
    return 0;
}