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

    setIO("traffic");

    int n; cin >> n;
    string s[100];
    int v[100];
    int d[100];

    for (int x = 0; x < n; x++) {
        cin >> s[x] >> v[x] >> d[x];
    }


    int f = 0; int z = 100000;

    for (int x = n-1; x >= 0; x--) {
        if (s[x] == "on") {
            z-= v[x];
            f-=d[x];
        }
        else if (s[x] == "none") {
            z = min(d[x], z);
            f = max(max(f, v[x]), 0);
        }
        else {
            z+=d[x];
            f+=v[x];
        }
    }

    if (f < 0) {
        f = 0;
    }

    cout << f << " " << z << endl;

    int f2 = 0; int z2 = 100000;

    for (int x = 0; x < n; x++) {
        if (s[x] == "on") {
            z2+= d[x];
            f2+=v[x];
        }
        else if (s[x] == "none") {
            z2 = min(d[x], z2);
            f2 = max(0, max(f2, v[x]));
        }
        else {
            z2-=v[x];
            f2-=d[x];
        }
    }

    if (f2 < 0) {
        f2 = 0;
    }

    cout << f2 << " " << z2 << endl;


}
