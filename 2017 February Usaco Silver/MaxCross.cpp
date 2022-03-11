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
    setIO("maxcross");
    ios::sync_with_stdio(false);
	cin.tie(0);

    // find the prefix sum of how many crosswalks are broken in a particular interval


    int n, k, b; cin >> n >> k >> b;
    vector<int> psum(n+1, 0);
    vector<int> v(n, 0);
    for  (int x = 0; x < b; x++) {
        int temp; cin >> temp;
        v[temp-1] = 1;
    }
    for (int x = 1; x <= n; x++) {
        psum[x] = psum[x-1] + v[x-1];
    }

    

    map<int, int> m;
    int ans = n;
    for (int x = 1; x <= n; x++) {
        if (m.count(x-k)) {
            ans = min(ans, psum[x] - psum[x-k]);
        }
        m[x]++;
    }
    cout << ans << endl;
    

}
