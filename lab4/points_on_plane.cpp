#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int casos;
    long long n;
    cin >> casos;

    for (int i = 0; i < casos; i++) {
        cin >> n;
        double a = sqrt(n);
        long long b = ceil(a);
        if (b*b < n) {
            b++;
        }  
        b--;
        cout << b << endl;
    }

}