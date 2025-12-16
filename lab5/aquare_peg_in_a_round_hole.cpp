#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <cmath>

using namespace std;

int main() {
    int terrenos, casasC, casasQ;
    cin >> terrenos >> casasC >> casasQ;

    vector<int> listT(terrenos);
    vector<int> listC;


    for (int t = 0; t < terrenos; t++) {
        cin >> listT[t];
    }

    for (int c = 0; c < casasC; c++) {
        int raio;
        cin >> raio;
        listC.push_back(raio);
    }

    for (int q = 0; q < casasQ; q++) {
        int lado;
        cin >> lado;
        int a = lado*lado;
        int r = sqrt(a+a)/2;
        listC.push_back(r);
    }

    sort(listT.begin(), listT.end());
    sort(listC.begin(), listC.end());

    int contagem = 0;
    for (int t : listT) {
        if (!listC.empty() && listC.front() < t) {
            listC.erase(listC.begin());
            contagem++;
        }
    }

    cout << contagem << endl;
}