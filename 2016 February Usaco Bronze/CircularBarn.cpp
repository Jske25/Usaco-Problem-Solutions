#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {

    setIO("cbarn");

    int n; cin >> n;
    vector<int> v(n);
    int total = 0;
    int ans2 = 999999999;
    for (int x = 0; x < n; x++) {
        cin >> v[x];
        total = total + v[x];
    }
    for (int x = 0; x < n; x++) {
        int temp = total;
        int ans = 0;
        for (int i = x; i < x + n; i++) {
            temp = temp - v.at(i%n);
            ans = ans + (temp);
        }
        ans2 = min(ans2, ans);

    }

    cout << ans2 << endl;
}
