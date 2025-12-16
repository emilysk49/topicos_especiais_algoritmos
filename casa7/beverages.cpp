#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <utility> 
#include <map>
#include <set>

using namespace std;

int main() {
    int qnt;
    int casos = 1;
    while (cin >> qnt) {
        map<string, int> bebidas;

        for (int i = 1; i <= qnt; i++) {
            string bebida;
            cin >> bebida;
            bebidas[bebida] = i;
        }

        int nos;
        cin >> nos;
        vector<vector <int>> grafo(qnt+1);
        vector<int> antes(qnt+1, 0);

        string menor, maior;
        for (int i = 0; i < nos; i++) {
            cin >> menor >> maior;
            int a = bebidas[menor];
            int b = bebidas[maior];
            grafo[a].push_back(b);
            antes[b]++;
        }

        set<int> primeiros;
        for (int i = 1; i <= qnt; i++) {
            if (antes[i] == 0) {
                primeiros.insert(i);
            }
        }

        vector<string> ordem;
        while (!primeiros.empty()) {
            int u = *primeiros.begin();
            primeiros.erase(primeiros.begin());
            string bebidaNome;
            for (auto& [nome, id] : bebidas) {
                if (id == u) bebidaNome = nome;
            }
            ordem.push_back(bebidaNome);

            for (int v : grafo[u]) { 
                antes[v]--;
                if (antes[v] == 0) primeiros.insert(v);
            }
        }

        cout << "Case #" << casos << ": Dilbert should drink beverages in this order: ";
        for (int i = 0; i < ordem.size(); i++) {
            cout << ordem[i];
            if (i != ordem.size() - 1) cout << " ";
        }
        cout << "." << endl;
        cout << "\n";
        casos++;
    }
}