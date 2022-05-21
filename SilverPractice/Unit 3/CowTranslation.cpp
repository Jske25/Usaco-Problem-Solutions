#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    vector<string> v;
    int ans = 0;
    string dummy; getline(cin, dummy);
    for (int x = 0; x < a; x++) {
        string s; getline(cin, s);
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int x = 0; x < b; x++) {
        bool ok = true;
        
        string s; getline(cin, s);
        if (lower_bound(v.begin(), v.end(), s) - v.begin() >= a) {
            continue;
        }
        string d = v[lower_bound(v.begin(), v.end(), s) - v.begin()];
        
        
        for (int i = 0; i < min(s.size(), d.size()); i++) {
            if (s[i] != d[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
}
