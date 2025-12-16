#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>

using namespace std;

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int qntEdi;
        cin >> qntEdi;
        
        vector<int> alturas(qntEdi);
        vector<int> larguras(qntEdi);
        vector<int> cresc(qntEdi);
        vector<int> desc(qntEdi);

        for (int i = 0; i < qntEdi; i++) {
            cin >> alturas[i];
        }
        for (int i = 0; i < qntEdi; i++) {
            cin >> larguras[i];
            cresc[i] = larguras[i];
            desc[i] = larguras[i];
        }

        for (int frente = 0; frente < qntEdi; frente++) {
            for (int anterior = 0; anterior < frente; anterior++) {
                if (alturas[anterior] < alturas[frente]) { //se eh crescente
                    cresc[frente] = max(cresc[frente], cresc[anterior] + larguras[frente]);
                } else if (alturas[anterior] > alturas[frente]) { //se eh descrescente
                    desc[frente] = max(desc[frente], desc[anterior] + larguras[frente]);
                }
            }
        }

        int maiorC = *max_element(cresc.begin(), cresc.end());
        int maiorD = *max_element(desc.begin(), desc.end());

        if (maiorC >= maiorD) {
            cout << "Case " << c+1 << ". Increasing (" << maiorC << "). Decreasing (" << maiorD << ")." << endl;
        } else {
            cout << "Case " << c+1 << ". Decreasing (" << maiorD << "). Increasing (" << maiorC << ")." << endl;
        }
    }
}