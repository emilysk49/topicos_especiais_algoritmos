#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
int a, b, c;

int main() {
    int casos;
    cin >> casos;

    for (int ci = 0; ci < casos; ci++) {
        cin >> a >> b >> c;
        
        bool achou = false;
        int res_x, res_y, res_z;

        for (int x = -100; x <= 100; x++) {
            if (achou) break;
            for (int y = -100; y <= 100; y++) {
                if (achou) break;
                if (x == y) continue;
                int z = a - x - y; // x + y + z = a
                if (z == x || z == y) continue;
                if (x+y+z == a && x*y*z == b && x*x + y*y + z*z == c) {
                    if (!achou || x < res_x || (x == res_x && y < res_y)) {
                        res_x = x;
                        res_y = y;
                        res_z = z;
                        achou = true;
                    }
                }
            }
        }

        if (achou) {
            cout << res_x << " " << res_y << " " << res_z << endl;
        } else {
            cout << "No solution." << endl;
        }
    }
}