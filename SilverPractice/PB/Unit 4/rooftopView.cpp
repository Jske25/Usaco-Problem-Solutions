#include <bits/stdc++.h>
using namespace std;

///flood fill problem

int w, h;
vector<vector<char>> v;
int cnt = 0;
int currentsize = 0;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    
        currentsize++;
        v[x][y] = '1';
    
    for (int i = 0; i < 4; i++) {
        int xx = x + di[i];
        int yy = y + dj[i];
        
        if (xx < 0 || xx >= h || yy < 0 || yy >= w || v[xx][yy] != '*') {
            continue;
        }
        
        
    
        dfs(xx, yy);
        
    }
    return;
}

int main() {
    cin >> w >> h;
    
    int ans = 0;
    
    
    v.resize(h, vector<char>(w));
    for (int x = 0; x < h; x++) {
        for (int i = 0; i < w; i++) {
            cin >> v[x][i];
        }
    }
    
    for (int x = 0; x < h; x++) {
        for (int i = 0; i < w; i++) {
            if (v[x][i] == '*') {
                cnt++;
                currentsize = 0;
                dfs(x, i);
                ans = max(ans, currentsize);
                
            }
        }
    }
    
    cout << ans << endl;
    
    
}
