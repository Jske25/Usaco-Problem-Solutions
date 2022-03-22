#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> v;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int L = 0;
    int R = n-1;
    int ans = 0;
    while (L < R) {
        if (!(v[R] + v[L] <= q)) {
            R--;
        }
        else if (v[R] + v[L] <= q) {
            L++;
            ans = ans + (R - L + 1);
        }
    }
    cout << ans << endl;
}
