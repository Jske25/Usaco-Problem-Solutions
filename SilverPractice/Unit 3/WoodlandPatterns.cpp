#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> v;
    int ans = 0;
    for (int x = 0; x < n; x++) {
        string s; cin >> s;
        string a; cin >> a;
        string ok = "";
        ok = ok + s.at(0) + s.at(1) + a.at(0) + a.at(1);
        v.push_back(ok);
    }
    sort(v.begin(), v.end());
    for (int x = 0; x < n; x++){
        string no = "";
        no = no + v[x][2] + v[x][3] + v[x][0] + v[x][1];
        bool ok = false;
        if (no[0] == no[2] && no[1] == no[3]) {
            continue;
        }
        if (no == v[x]) {
            ans--;
        }
        
        
        
        ans += (upper_bound(v.begin(), v.end(), no) - lower_bound(v.begin(), v.end(), no));

        
        
        
        
    }
    
    cout << ans / 2 << endl;
    
    
    
}
