#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int n;
vector<int> cores;
vector<vector<int>> arvore;
vector<int> res;

set<int> dfs(int u, int prox){
    set<int> cores_set;
    set<int> filho;
    cores_set.insert(cores[u]); 

    for (int v : arvore[u]) {
        if (v == prox) continue;
        filho = dfs(v, u);
        if (filho.size() > cores_set.size()) {
            swap(filho, cores_set);
        }
        cores_set.insert(filho.begin(), filho.end());
    }
    res[u] = cores_set.size();
    return cores_set;
}

int main() {
    int u, v;
    cin >> n;
    cores.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cores[i];
    }
    arvore.assign(n, {});
    res.assign(n, 0);

    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--; 
        v--;
        arvore[u].push_back(v);
        arvore[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}