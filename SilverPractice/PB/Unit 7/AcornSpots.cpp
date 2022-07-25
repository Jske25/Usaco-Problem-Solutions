#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

ll start;
ll n, m;
vector<pair<ll, ll>> v;



bool isvalid(ll a) {
    ll i = 0;
    ll amt = 0;
    start = v[0].f;
    
    while (amt < n) {
        if (v[i].f >= start) {
            start = v[i].f;
        }
        if (v[i].f <= start && v[i].s >= start) {
            amt++;
            start += a;
        }
        else {
            i++;
        }
        
        if (i >= v.size()) {
            return false;
        }
    }
    return true;
    
}

int main() {
    cin >> n >> m;
    for (ll x = 0; x < m; x++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll l = 1; ll r = 1e18; ll mid;
    ll res = -1;
    start = v[0].first;
    
    while (l < r) {
        mid = l + (r-l)/2;
        if (isvalid(mid)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    
    cout << res << endl;
}
