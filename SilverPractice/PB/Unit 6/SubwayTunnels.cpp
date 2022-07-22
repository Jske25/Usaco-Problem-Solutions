#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5;
const int MX = 252;
int n, m; 
int grid[MX][MX];
vector<bool> visited;


void dfs(int b) {
    for (int x = 1; x <= n; x++) {
        if (grid[b][x] == 1) {
            visited[x] = false;
            grid[x][b] = 0;
            grid[b][x] = 0;
            dfs(x);
        }
    }
    return;
}


int main() {
    cin >> n >> m;
    visited.resize(n+1, true);
    
    for (int x = 1; x <= n; x++) {
        for (int i = 1; i <= n; i++) {
            grid[x][i] = INF;
        }
    }
    
    for (int x = 1; x <= n; x++) {
        grid[x][x] = 0;
    }
    
    for (int x = 0; x < m; x++) {
        int a, b; cin >> a >> b;
        grid[a][b] = 1;
        grid[b][a] = 1;
    }
    
    visited[1] = false;
    dfs(1);
    
    bool temp = true;
    for (int x = 1; x <= n; x++) {
        if (visited[x] == true) {
            temp = false;
            cout << x << endl;
        }
    }
    if (temp) {
        cout << 0 << endl;
    }
    
}
