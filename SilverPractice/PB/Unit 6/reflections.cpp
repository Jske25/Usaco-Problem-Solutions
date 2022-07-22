#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> v;
int ans = 0;
int direction = 1; // 1 means towards up, 2 means towards down, 3 means to the right, and 4 means to the left
int counter;

void dfs(int a, int b) {
    if (v[a][b] == '/') {
        if (direction == 2) {
            b = b-1;
            direction = 4;
        }
        else if (direction == 1) {
            b++;
            direction = 3;
        }
        else if (direction == 3) {
            direction = 1;
            a--;
        }
        else if (direction == 4) {
            direction = 2;
            a++;
        }
        
    }
    else if (v[a][b] == 'a') {
        if (direction == 1) {
            direction = 4;
            b--;
        }
        else if (direction == 2) {
            b++;
            direction = 3;
        }
        else if (direction == 3) {
            a++;
            direction = 2;
        }
        else if (direction == 4) {
            direction = 1;
            a--;
        }
    }
    if (a >= n || a < 0 || b >= m || b < 0) {
        return;
    }
    counter++;
    dfs(a, b);
}

int main() {
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < m; i++) {
            cin >> v[x][i];
            if (v[x][i] != '/') {
                v[x][i] = 'a';
            }
        }
    }

    
    for (int x = 0; x < m; x++) {
        direction = 2;
        counter = 1;
        dfs(0, x);
        ans = max(ans, counter);
    }
    for (int x = 0; x < n; x++) {
        direction = 4;
        int counter = 1;
        dfs(x, m-1);
        ans = max(ans, counter);
    }
    for (int x = 0; x < m; x++) {
        direction = 1;
        counter = 1;
        dfs(n-1, x);
        ans = max(ans, counter);
    }
    for (int y = 0; y < n; y++) {
        direction = 3;
        counter = 1;
        dfs(y, 0);
        ans = max(ans, counter);
    }
    
    cout << ans << endl;
    
    
    
}
