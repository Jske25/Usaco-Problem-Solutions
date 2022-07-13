#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<char>> v(r+1, vector<char>(c+1, '0'));
    vector<vector<int>> s(r+1, vector<int>(c+1, 0));
    for (int x = 1; x <= r; x++) {
        for (int i = 1; i <= c; i++) {
            cin >> v[x][i];
        }
    }
    int cnt = 0;
    bool breaker = false;
    for (int x = 1; x <= r; x++) {
        for (int i = 1; i <= c; i++) {
            if (v[x][i] == 'R') {
                continue;
            }
            if (v[x][i] == 'B') {
                cnt++;
                s[x][i] = 1;
            }
            s[x][i] = s[x-1][i] + s[x][i-1]+s[x][i];
            if (cnt == 2) {
                cout << s[x][i]-1 << endl;
                breaker = true;
                break;
            }
            
        }
        if (breaker) {
            break;
        }
    }
}
