#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(pair<ll, ll> p, pair<ll, ll> t) {
    if (p.first != t.first) {
        return p.first < t.first;
    }
    return p.second > t.second;
}

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> v;
    for (ll x = 0; x < n; x++) {
        ll a, b; cin >> a >> b;
        ll x1 = a - b;
        ll x2 = a + b;
        v.push_back({x1, x2});
    }
    sort(v.begin(), v.end(), cmp);
    ll invis = 0;
    ll end = v[0].second;
    for (ll x = 1; x < v.size(); x++) {
        if (v[x].second <= end) {
            invis++;
            continue;
        }
        end = v[x].second;
    }
    
    cout << n - invis << endl;
}
