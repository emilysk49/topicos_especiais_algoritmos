#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <deque>
using namespace std;

int main() {
    int n;
    string comando;
    deque<int> fila;
    bool invertido = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> comando;
        if (invertido) {
            if (comando == "back") {
                comando = "front";
            } else if (comando == "front") {
                comando = "back";
            } else if (comando == "toFront") {
                comando = "push_back";
            } else if (comando == "push_back") {
                comando = "toFront";
            } else if (comando == "reverse") {
                invertido = false;
                continue;
            }
        }

        if (comando == "back") {
            if (!fila.empty()) {
                cout << fila.back() << endl;
                fila.pop_back();
            } else {
                cout << "No job for Ada?" << endl;
            }
        } else if (comando == "front") {
            if (!fila.empty()) {
                cout << fila.front() << endl;
                fila.pop_front();
            } else {
                cout << "No job for Ada?" << endl;
            }
        } else if (comando == "reverse") {
            invertido = true;
        } else if (comando == "toFront") {
            int num;
            cin >> num;
            fila.push_front(num);
        } else if (comando == "push_back") {
            int num;
            cin >> num;
            fila.push_back(num);
        }
    }
}