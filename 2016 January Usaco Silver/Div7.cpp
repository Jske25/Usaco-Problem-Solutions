#include <bits/stdc++.h>
using namespace std;

#define long long int;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {
    setIO("div7");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    vector<int> v(n+1, 0);
    for (int x = 1; x <= n; x++) {
        cin >> v[x];
        v[x] = (v[x-1] + v[x]) % 7;
    }
    vector<int> r(7);
    vector<int> l(7);

    for (int x = 1; x < v.size(); x++) {
        r[v[x]] = x;
    }
    for (int x = v.size()-1; x >= 1; x--) {
        l[v[x]] = x;
    }
    int ans = 0;
    for (int x = 0; x <= 6; x++) {
        ans = max(ans, r[x] - l[x]);
    }
    cout << ans << endl;
}
