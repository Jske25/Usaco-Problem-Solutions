#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;
int ans = 0;

void dfs(int a, int b, int temp) {
    if (a == n-1 || b == n-1) {
        ans = max(ans, temp);
        return;
    }
    
    dfs(a+1, b, temp + v[a+1][b]);
    
    
    dfs(a+1, b+1, temp + v[a+1][b+1]);
    
}

int main() {
    cin >> n;
    v.resize(n, vector<int>(n, 0));
    int t = 0;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i <= t; i++) {
            int temp; cin >> temp;
            v[x][i] = temp;
        }
        t++;
    }
    
    dfs(0, 0, v[0][0]);
    
    cout << ans << endl;
    

    
    
    
}


