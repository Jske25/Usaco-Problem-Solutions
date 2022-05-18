#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> v(r+1, vector<int>(c+1, 0));
    int ans = 0;
    for (int x = 0; x < r; x++) {
        for (int i = 0; i < c; i++) {
            cin >> v[x][i];
        }
    }
    for (int x = 0; x < r; x++) {
        for (int i = 0; i < c; i++) {
            if (v[x][i] <= ans) {
                continue;
            }
            else {
                if (v[x][i] == v[x+1][i] || v[x][i] == v[x][i+1] || v[x][i] == v[x+1][i+1]) {
                    ans = max(ans, v[x][i]);
                }
                else if (i >= 1 && v[x][i] == v[x+1][i-1]) {
                    ans = max(ans, v[x][i]);
                }
            }
        }
    }  
    cout << ans << endl;
    
}
