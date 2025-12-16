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

vector<long long> gerarFib(long long maior) {
    vector<long long> fib = {1,2};
    while (true) {
        long long prox = fib[fib.size()-1] + fib[fib.size()-2];
        if (prox > maior) break;
        fib.push_back(prox);
    }
    return fib;
}

int main() {
    int casos;
    cin >> casos;

    for (int c = 0; c < casos; c++) {
        int qnt;
        cin >> qnt;
        vector<long long> nums(qnt);
        long long maior;
        for (int i = 0; i < qnt; i++) {
            cin >> nums[i];
            if (i == 0) {
                maior = nums[i];
            } else if (nums[i] > maior) {
                maior = nums[i];
            }
        }
        string cifra;
        cin.ignore();
        getline(cin, cifra);

        string letras = "";
        for (char carac : cifra) {
            if (isupper(carac)) letras += carac;
        }

        vector<long long> fib = gerarFib(maior);
        string resposta(fib.size(), ' ');

        int indice = 0;
        for (long long n : nums) {
            //procurar numero dentro de seq. de fib.
            auto it = find(fib.begin(), fib.end(), n);
            //se achou e ainda nao percorreu todas caracteres de cifra
            if (it != fib.end() && indice < letras.size()) {
                int pos = it - fib.begin();
                //if (resposta.size() <= pos) resposta.resize(pos + 1, ' ');
                resposta[pos] = letras[indice++];
            }
        }
        while (!resposta.empty() && resposta.back() == ' ') resposta.pop_back();
        cout << resposta << endl;
    }
}