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

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void invs(long long a, long long b) {
    // long long x, y;
    // long long g = gcd(a, b, x, y);
    // long long res = (x % b + b) % b;
    // return res;

    long long x, y;
    long long g = gcd(a, b, x, y);
    if (g != 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        x = (x % b + b) % b;
        if (x == 0) {
            cout << "2" << endl;
        } else {
            cout << x << endl;
        }
    }
    return;

}

int main() {
    int casos;
    cin >> casos;
    
    for (int c = 0; c < casos; c++) {
        long long criancas, balas;
        cin >> criancas >> balas;
        if (balas == 1) {
            cout << criancas+1 << endl;
        } else  {
            invs(balas, criancas);
        }
        
        // long long bolsas = invs(balas, criancas);
        // if (bolsas == 1) {
        //     cout << "IMPOSSIBLE" << endl;
        // } else {
        //     cout << bolsas << endl;
        // }
    }
}