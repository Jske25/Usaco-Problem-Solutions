#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n; cin >> n;
    vector<int> v(2*n+1, 0);
    vector<int> bunny;
    vector<int> harry;
    int ans = 0;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        bunny.push_back(temp);
        v[temp]++;
    }
    for (int x = 1; x <= 2*n; x++) {
        if (v[x] == 0) {
            harry.push_back(x);
        }
    }
    sort(harry.begin(), harry.end(), cmp);
    sort(bunny.begin(), bunny.end(), cmp);
    
    while (harry.size() != 0 || bunny.size() != 0) {
        if (harry[0] < bunny[0]) {
            harry.pop_back();
            bunny.erase(bunny.begin());
        }
        else {
            ans++;
            bunny.erase(bunny.begin());
            harry.erase(harry.begin());
        }
    }
    
    cout << ans << endl;
    
}
