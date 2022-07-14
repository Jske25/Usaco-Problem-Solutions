#include <bits/stdc++.h>
using namespace std;


const int MX = 1e5 + 10;

int n; int q;

vector<vector<int>> adj;

vector<int> d;

vector<bool> visited;



void dfs(int u, int p) {
    
    for (int v = 0; v < n; v++) {
        if (adj[u][v] != 0 && adj[u][v] != MX && visited[v] == false) {
            d[v] = d[u] + adj[u][v];
            visited[v] = true;
            dfs(v, v);
            
        }
        
    }
    
    return;
}



int main() {
    cin >> n >> q;
    
    adj.resize(n, vector<int>(n, MX));
    d.resize(n);
    visited.resize(n, false);
    
    for (int x = 0; x < n; x++) {
        adj[x][x] = 0;
    }
    
    for (int x = 2; x <= n; x++) {
        int a, b, c; cin >> a >> b >> c;
        
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
        
    }
    for (int x = 0; x < q; x++) {
        int a, b; cin >> a >> b;
        
        for (int x = 0; x < d.size(); x++) {
            d[x] = MX;
            visited[x] = false;
        }
        d[a-1] = 0;
        visited[a-1] = true;
        
        dfs(a-1, a-1);
        
        cout << d[b-1] << endl;
        
    }
    
    
   
    
    
}
