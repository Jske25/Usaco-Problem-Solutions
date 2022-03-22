#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    int ans = INT_MAX;
    for (int x = 0; x <= 83; x++) {
        int y = x + 17;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < x) {
                counter += (x-v[i])*(x-v[i]);
            }
            if (v[i] > y) {
                counter += (v[i]-y)*(v[i]-y);
            }
        }
        ans = min(ans, counter);
    }
    cout << ans << endl;
}
