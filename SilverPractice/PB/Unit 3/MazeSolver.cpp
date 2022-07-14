#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> v;

string ans = "";

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int startx, starty, endx, endy;

bool found = false;


void dfs(int r, int c) {
    if (found) {
        return;
    }
    if (v[r][c] == 'F') {
        found = true;
        cout << ans << endl;
        return;
        
    }
    
    v[r][c] = '*';
    
    for (int i = 0; i < 4; i++) {
        int row = r + di[i];
        int col = c + dj[i];
        if (row < 0 || row > n || col < 0 || col > m || v[row][col] == '#' || v[row][col] == '*') {
            continue;
        }
        if (row > r) {
            ans = ans + 'D';
        }
        else if (row < r) {
            ans = ans + 'U';
        }
        else if (col < c) {
            ans = ans + 'L';
        }
        else {
            ans = ans + 'R';
        }
        dfs(row, col);
        
        ans.pop_back();
        v[r][c] = '.';
    }
    return;

}

int main() {
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < m; i++) {
            cin >> v[x][i];
            if (v[x][i] == 'S') {
                startx = x;
                starty = i;
            }
            else if (v[x][i] == 'F') {   
                endx = x;
                endy = i;
            }
        }
    }
    dfs(startx, starty);
    
    
    
}
