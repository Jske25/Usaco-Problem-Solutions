#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {

    setIO("cowsignal");

    int m, n, k; cin >> m >> n >> k;
    vector<vector<char>> v(m, vector<char> (n));
    for (int x = 0; x < m; x++) {
        for (int i = 0; i < n; i++) {
            cin >> v[x][i];
        }
    }
    for (int x = 0; x < m; x++) {
        for (int z = 0; z < k; z++) {
            for (int i = 0; i < n; i++) {
                for (int z = 0; z < k; z++) {
                    cout << v[x][i];
                }
            }
            cout << endl;

        }

    }

}
