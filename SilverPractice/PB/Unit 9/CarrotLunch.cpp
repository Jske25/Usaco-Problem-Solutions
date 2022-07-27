#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int counter2 = 0;
    vector<int> v;
    vector<int> psum(n+1, 0);
    for (int x = 0; x < n; x++) {
        int t; cin >> t;
        v.push_back(t);
        if (t==2) {
            counter2++;
        }
    }
    for (int x = 1; x <= n; x++) {
        if (v[x-1] == 2) {
            psum[x] = psum[x-1] + 1;
        }
        else {
            psum[x] = psum[x-1];
        }
    }
    
    int ans = INT_MAX;
    
    for (int x = 0; x <= n; x++) {
        int twosL = psum[x];
        int twosR = counter2 - psum[x];
        int onesL = x - psum[x];
        int onesR = n - twosL - twosR - onesL;
        
        ans = min(ans, onesR + twosL);
        
    }
    
    cout << ans << endl;
}
