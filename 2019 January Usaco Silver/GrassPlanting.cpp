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

    setIO("planting");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    int maxer = 0;

    for (int x = 0; x < n-1; x++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 0; x < n-1; x++) {
        maxer = max(maxer, (int)adj[x].size());
    }
    cout << maxer+1 << endl;

}
