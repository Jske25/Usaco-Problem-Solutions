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

    setIO("factory");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    int enter[101]; int exit[101];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        exit[a]++;
        enter[b]++;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (ans != -1 && exit[i] == 0) {
            ans = -1;
            break;
        }
        if (exit[i] == 0) {
            ans = i;
        }
    }
    cout << ans << endl;
}
