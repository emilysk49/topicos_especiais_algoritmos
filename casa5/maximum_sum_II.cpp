#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) break;

        int num;
        bool zeros = true;
        for (int i = 0; i < n; i++) {
            cin >> num;

            if (num > 0) {
                if (zeros) {
                    cout << num;
                } else {
                    cout << " " << num;
                }
                zeros = false;
            }
        }
        if (zeros) {
            cout << "0" << endl;
        } else {
            cout << endl;
        }
    }
}