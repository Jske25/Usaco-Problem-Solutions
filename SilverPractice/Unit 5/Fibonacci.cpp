#include <bits/stdc++.h>
using namespace std;

int Fib(int x) {
    if (x == 1) {
        return 1;
    }
    else if (x == 2) {
        return 1;
    }
    else {
        return Fib(x-1) + Fib(x - 2);
    }
}

int main() {
    int a; cin >> a;
    cout << Fib(a) << endl;
    
}
