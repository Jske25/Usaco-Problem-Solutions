#include <bits/stdc++.h>
using namespace std;

#define long long int;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {
    setIO("hps");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;

    vector<int> p(n, 0);
    vector<int> h(n, 0);
    vector<int> s(n, 0);
    for (int x = 0; x < n; x++) {
        char temp; cin >> temp;
        if (temp == 'P') {
            p[x]++;
        }
        else if (temp == 'H') {
            h[x]++;
        }
        else {
            s[x]++;
        }
    }
    vector<int> prefix_p(n+1, 0);
    vector<int> prefix_h(n+1, 0);
    vector<int> prefix_s(n+1, 0);

    for (int x = 1; x <= n; x++) {
        prefix_s[x] = s[x-1] + prefix_s[x-1];
        prefix_h[x] = h[x-1] + prefix_h[x-1];
        prefix_p[x] = p[x-1] + prefix_p[x-1];
    }
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int phase_1 = max(max(prefix_s[x],prefix_p[x]), prefix_h[x]);
        int phase_2 = max(max(prefix_h[n] - prefix_h[x], prefix_s[n] - prefix_s[x]), prefix_p[n] - prefix_p[x]);
        ans = max(ans, phase_1 + phase_2);
    }

    cout << ans << endl;


}
