#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    int L = 0; int R = 0;
    for (int x = 0; x < n ; x++) {
        int a; char c; cin >> a >> c;
        if (c == 'R') {
            R = a + R;
            v.push_back({R, -1});
            v.push_back({L, 1});
            L = R;
        }
        else {
            L = L - a;
            v.push_back({L, 1});
            v.push_back({R, -1});
            R = L;
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int begin;
    bool ok = false;
    bool f = false;
    int counter = 0;
    for (int x = 0; x < v.size(); x++) {
        ans += v[x].second;
        if (ans >= 2 && !ok) {
            begin = v[x].first;
            ok = true;
            f = true;
        }
        else if (f && ans < 2) {
            int temp = v[x].first;
            counter += (temp - begin);
            ok = false;
            f = false;
        }
    }
    cout << counter << endl;
}
