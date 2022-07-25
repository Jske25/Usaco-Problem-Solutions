#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>p, pair<int, int> t) {
    if (p.second != t.second) {
        return p.second < t.second;
    }
    return p.first < t.first;
}


int main() {
    int n, s; cin >> n >> s;
    vector<int> m;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        m.push_back(temp);
    }
    vector<pair<int, int>> v;
    for (int x = 0; x < s; x++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(m.begin(), m.end());
    
    sort(v.begin(), v.end(), cmp);
    
    int ans = 0;
    for (int x = 0; x < v.size(); x++) {
        auto ok =  lower_bound(m.begin(), m.end(), v[x].first);
        if (*ok <= v[x].second && ok != m.end()) {
            ans++;
            m.erase(ok);
        }
    }
    
    cout << ans << endl;
    
}
