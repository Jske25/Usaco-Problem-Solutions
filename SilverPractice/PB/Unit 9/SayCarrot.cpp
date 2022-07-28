#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    map<ll, ll> m;
    ll x = n % 8;
    ll y = n / 8;
    m[1] = 1;
    m[2] = 2;
    m[3] = 4;
    m[4] = 7;
    m[5] = 8;
    m[6] = 11;
    m[7] = 13;
    m[0] = 14;
    m[8] = 14;
    
    if (x == 0) {
        y--;
    }
    
    cout << m[x] + y*15 << endl;
    
    
    
    
}
