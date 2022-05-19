#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    vector<int> z;
    for (int x = 0; x < n; x++) {
        int t; cin >> t;
        v.push_back(t);
    }
    int c; cin >> c;
    vector<int> d;
    for (int x = 0; x < c; x++) {
        int t; cin >> t;
        d.push_back(t);
    }
    sort(d.begin(), d.end());
    for (int x = 0; x < n-c+1; x++) {
        vector<int> temp(c);
        for (int i = x; i < x + c; i++) {
            temp[i-x] = v[i];
        }
        sort(temp.begin(), temp.end());
        int checker;
        bool ok = true;
        for (int k = 0; k < c; k++) {
            if (k != 0) {
                if ((temp[k] - d[k]) != checker) {
                    ok = false;
                    break;
                }
            }
            checker = temp[k] - d[k];
        }
        if (ok) {
            z.push_back(x+1);
        }
    }
    cout << z.size() << endl;
    for (int x = 0; x < z.size(); x++) {
        cout << z[x] << endl;
    }
}
