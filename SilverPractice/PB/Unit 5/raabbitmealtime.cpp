#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n, m; cin >> n >> m;
    vector<long long> v(n);
    vector<long long> y(n);
    vector<long long> hSeat(n, false);
    
    
    for (long long x = 0; x < n; x++) {
        cin >> v[x];
        cin >> y[x];
    }
    
    for (long long x = 0; x < m; x++) {
        long long d = 4000000000000000000LL;
        long long rabbit;
        long long sd;
        long long a, b; cin >> a >> b;
        for (long long i = 0; i < n; i++) {
            if (hSeat[i] == true) {
                continue;
            }
            sd = (a - v[i])*(a - v[i]) + (b - y[i])*(b - y[i]);
            if (sd < d) {
                d = sd;
                rabbit = i;
            }
        }
        hSeat[rabbit] = true;
    }
    
    bool ok = true;
    
    for (long long i = 0; i < n; i++) {
        if (hSeat[i] == false) {
            ok = false;
            cout << i +1 << endl;
        }
    }
    if (ok) {
        cout << 0 << endl;
    }
    
}
