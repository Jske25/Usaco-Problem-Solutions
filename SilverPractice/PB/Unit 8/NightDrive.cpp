#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, T, U, F, D;
    cin >> M >> T >> U >> F >> D;
    vector<char> v(T);
    
    U = U + D;
    D = U;
    F += F;
    
    int ans = 0;
    int counter = 0;
    int temp;
    for (int x = 0; x < M; x++) {
        cin >> v[x];
    }
    for (int x = 0; x < M; x++) {
        if (v[x] == 'u') {
            ans+=U;
            counter += 2;
        }
        else if (v[x] == 'f') {
            ans += F;
            counter += 2;
        }
        else if (v[x] == 'd') {
            ans += D;
            counter += 2;
        }
        
        if (ans < M) {
            temp = counter;
        }
        else if (ans == M) {
            break;
        }
        else if (ans > M) {
            counter = temp;
            break;
        }
    }
    
    cout << counter/2 << endl;
}
