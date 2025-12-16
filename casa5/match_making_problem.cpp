#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 

using namespace std;

int main() {
    int b, s;
    int casos = 1;
    while (true) {
        cin >> b >> s;
        if (b == 0 && s == 0) break;

        bool maisMulher;
        int solteiros;
        //vector<int> pilha;
        
        if (b < s) {
            maisMulher = true;
            solteiros = 0;
        } else {
            maisMulher = false;
            solteiros = b - s;
        }

        int idade;
        int menor = 61;
        for (int i = 0; i < b; i++) {
            cin >> idade;
            if (!maisMulher) {
                if (menor > idade) menor = idade;
            }
        }
        //sort(pilha.begin(), pilha.end());

        for (int i = 0; i < s; i++) {
            cin >> idade;
        }

        if (solteiros == 0) {
            cout << "Case " << casos << ": 0" << endl;
        } else {
            cout << "Case " << casos << ": "<< solteiros << " " << menor << endl;
        }

        casos++;
    }
    
}