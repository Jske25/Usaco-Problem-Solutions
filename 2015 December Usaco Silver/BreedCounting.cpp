#include <bits/stdc++.h>
using namespace std;

//solution inspiration: Prefix Sums

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {
    setIO("bcount");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> h(n+1, 0);
    vector<int> g(n+1, 0);
    vector<int> j(n+1, 0);
    for (int x = 1; x <= n; x++) {
        int temp; cin >> temp;
        if (temp == 2) {
            g[x]++;
        }
        else if (temp == 1) {
            h[x]++;
        }
        else {
            j[x]++;
        }
    }
    vector<int> prefix_h(n+1, 0);
    vector<int> prefix_j(n+1, 0);
    vector<int> prefix_g(n+1, 0);
    for (int x = 0; x <= n; x++) {
        prefix_h[x] = prefix_h[x-1] + h[x];
    }
    for (int x = 1; x <= n; x++) {
        prefix_g[x] = prefix_g[x-1] + g[x];
    }
    for (int x = 1; x <= n; x++) {
        prefix_j[x] = prefix_j[x-1] + j[x];
    }
    while (q--) {
        int a, b; cin >> a >> b;
        cout << prefix_h[b] - prefix_h[a-1] << " " << prefix_g[b] - prefix_g[a-1] << " " << prefix_j[b] - prefix_j[a-1] << endl;

    }



}
