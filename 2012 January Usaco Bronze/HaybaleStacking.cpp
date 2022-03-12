#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {
    setIO("");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> v(n+1, 0);
    for (int x = 0; x < k; x++) {
        int a, b; cin >> a >> b;
        a--; b--;
        v[a]++;
        v[b+1]--;
    }
    for (int x = 1; x <= n; x++) {
        v[x] = v[x-1] + v[x];
    }
    sort(v.begin(), v.end());
    cout << (v[(1+n)/2]) << endl;

}
