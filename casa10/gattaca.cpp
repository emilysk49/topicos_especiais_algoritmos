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

pair<string, int> maiorSubString(string &s) {
    int tam = s.size();
    string maiorSub = "";
    int qnt = 0;

    // testa todos os comprimentos possiveis, do maior para o menor
    for (int n = tam; n >= 1; n--) {
        unordered_map<string, int> freq;
        for (int i = 0; i + n <= tam; i++) {
            string pedaco = s.substr(i, n);
            freq[pedaco]++;
        }

        vector<string> possiveis;
        for (auto &p : freq) {
            // verifica se tem mais de 2 repeticao
            if (p.second >= 2) {
                possiveis.push_back(p.first);
            }
        }

        if (!possiveis.empty()) {
            sort(possiveis.begin(), possiveis.end()); // menor lexicograficamente
            maiorSub = possiveis[0];
            qnt = freq[maiorSub];
            break; // achou a maior substring repetida
        }
    }
    return {maiorSub, qnt};
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        string dna;
        cin >> dna;
        pair<string, int> resp = maiorSubString(dna);
        if (resp.first == "") {
            cout << "No repetitions found!" << endl;
        } else {
            cout << resp.first << " " << resp.second << endl;
        }
    }
}