#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, Ns, H; cin >> R >> Ns >> H;
    vector<int> v(R, 0);
    
    for (int x = 0; x < Ns; x++) {
        int n, b, c; cin >> n >> b >> c;
        v[b] = n;
        v[c] = n;
    }
    
    vector<int> ans;
    int pos = H;
    ans.push_back(pos);
    
    while (pos != 1) {
        
        pos = v[pos];
        
        ans.push_back(pos);
    }
    
    cout << ans.size() << endl;
    for (int x = ans.size()-1; x >= 0; x--) {
        cout << ans[x] << endl;
    }
}
