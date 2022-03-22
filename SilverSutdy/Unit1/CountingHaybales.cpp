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
    for (int x = 0; x < q; x++) {
        int a, b; cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << endl;
    }
}
