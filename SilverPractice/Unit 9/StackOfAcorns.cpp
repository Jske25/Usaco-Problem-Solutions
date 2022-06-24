#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int ans = 0;

bool cmd(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

void Subset(int prevW, int prevH, int pos, int h) {
    if (pos == n) {
        ans = max(ans, h);
        return;
    }
    if (v[pos].first > prevW && v[pos].second > prevH) {
        Subset(v[pos].first, v[pos].second, pos+1, h+1);
    }
    Subset(prevW, prevH, pos+1, h);
}


int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmd);
    Subset(0, 0, 0, 0);
    cout << ans << endl;
    

}
