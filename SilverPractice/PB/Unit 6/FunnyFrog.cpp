#include <bits/stdc++.h>
using namespace std;

int r, c; 
vector<vector<char>> v;
int ans = 0;

void dfs(int a, int b) {
    if (a == r-1 && b == c-1) {
        ans++;
        return;
    }
    
    int row = a+1; int col = b+1;
    
    for (int x = row; x < r; x++) {
        for (int y = col; y < c; y++) {
            if (row > a && row < r && col < c && col > b && v[a][b] != v[x][y]) {
                dfs(x, y);
            }
        }
    }
}


int main() {
    cin >> r >> c;
    v.resize(r, vector<char>(c));
    for (int x = 0; x < r; x++) {
        for (int i = 0; i < c; i++) {
            cin >> v[x][i];
        }
    }
    dfs(0, 0);
    
    cout << ans << endl;
    
    
    
}
