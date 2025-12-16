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
    vector<long long> catalan = {
        1, 1, 2, 5, 14, 42, 132, 429, 1430,
        4862, 16796, 58786, 208012, 742900,
        2674440, 9694845, 35357670, 129644790,
        477638700, 1767263190
    };

    long long n;
    while (cin >> n) {
        // encontrar indice que gera exatamente n arvores
        int resp = -1;
        for (int i = 0; i < (int)catalan.size(); i++) {
            if (catalan[i] == n) {
                resp = i; // fica com o maior índice possível
            }
        }
        cout << resp << endl;
    }
}