#include <bits/stdc++.h>
using namespace std;

#define s second
#define f first


bool cmp(pair<int, int> p, pair<int, int> t) {
    if (p.f != t.f) {
        return p.f < t.f;
    }
    return p.s < t.s;
}

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    int maxVal = N*X;
    int ans = 0;
    vector<pair<int, int>> v;
    for (int x = 0; x < N; x++) {
        int a, b; cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 2});
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int x = 0; x < v.size(); x++) {
        if (v[x].s == 1) {
            maxVal += (Y-X);
        }
        else {
            maxVal += (Z-Y);
        }
        ans = max(ans, maxVal);
    }
    
    cout << ans << endl;
}
