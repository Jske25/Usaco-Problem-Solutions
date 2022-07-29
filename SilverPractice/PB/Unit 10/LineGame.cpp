#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int dist = 0;
    int net = 0;
    int marker = -1;
    vector<int> v(n);
    for (int x = 0; x < n; x++) {
        cin >> v[x];
    }
    for (int x = 0; x < n; x++) {
        dist++;
        net += v[x];
        if (marker != -1 && net >= 0) {
            dist += (x - marker)*2;
            marker = -1;
        }
        if (net < 0 && marker == -1) {
            marker = x;
        }
        
    }
    
    cout << dist << endl;
}
