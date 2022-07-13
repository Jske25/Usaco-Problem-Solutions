#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n+1, 0);
    for (int x = 0; x < n-1; x++) {
        int u, t; cin >> u >> t;
        v[u]++;
        v[t]++;
    }
    
    int min1 = 0;
    
    for (int x = 1; x <= n; x++) {
        min1 = max(v[x], min1);
        
    }
    
    cout << min1+1 << endl;
    
    
}
