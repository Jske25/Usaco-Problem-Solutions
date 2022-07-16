#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v(102, vector<char>(102, '.'));

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int cnt = 0;


void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
         int xx = x + di[i];
         int yy = y + dj[i];
         
         if (xx < 0 || xx >= 102 || yy < 0 || yy >= 102) {
             continue;
         }
         
         if (v[xx][yy] == '@') {
             cnt++;
         }
         
         
    }
    
    v[x][y] = 'x';
    
    for (int i = 0; i < 4; i++) {
        int xx = x + di[i];
        int yy = y + dj[i];
        
        if (xx < 0 || xx >= 102 || yy < 0 || yy >= 102) {
            continue;
        }
        
        if (v[xx][yy] == '.') {
            dfs(xx, yy);
        }
        
        
    }
}


int main() {
    int n; cin >> n;
    for (int x = 0; x < n; x++) {
        int a, b; cin >> a >> b;
        v[a][b] = '@';
    }
    bool ok = false;
    for (int x = 0; x <= 101; x++) {
        for (int i = 0; i <= 101; i++) {
            if (v[x][i] == '.') {
                dfs(x, i);
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    
    cout << cnt << endl;
}
