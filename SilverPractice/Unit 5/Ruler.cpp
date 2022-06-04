#include <bits/stdc++.h>
using namespace std;

void din(int x) {
    if (x == 1) {
        cout << "*" << endl;
        return;
    }
    else {
        din(x-1);
        for (int i = 0; i < x; i++) {
            cout << "*";
        }
        cout << endl;
        din(x-1);
    }
}

void rn(int x) {
    for (int i = 0; i < x; i++) {
        cout << "*";
    }
    cout << endl;
    din(x-1);
    for (int i = 0; i < x; i++) {
        cout << "*";
    }
    cout << endl;
    
    return;
    
}

int main() {
    int a; cin >> a;
    rn(a);
    
}
