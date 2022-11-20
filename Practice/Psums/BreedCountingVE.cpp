#include <bits/stdc++.h>
using namespace std;

/*
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define mi map<int, int>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i <=b; ++i)
#define f first
#define s second

*/

#define int long long
#define f first
#define s second

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}




signed main()
{
    setIO("bcount");

    int n, q;
    cin >> n >> q;

    vector<int> v(n, 0);

    vector<int> a(n+1, 0);
    vector<int> b(n+1, 0);
    vector<int> c(n+1, 0);

    for (int x = 0; x < n; x++) {
        cin >> v[x];
    }

    for (int x = 1; x <= n; x++) {
        if (v[x-1] == 1) {
            a[x]++;
        }
        else if (v[x-1] == 2) {
            b[x]++;
        }
        else {
            c[x]++;
        }
        a[x] = a[x-1] + a[x];
        b[x] = b[x-1] + b[x];
        c[x] = c[x-1] + c[x];
    }

    while (q--) {
        int e, t; cin >> e >> t;
        int t1, t2, t3;
        t1 = a[t] - a[e-1];
        t2 = b[t] - b[e-1];
        t3 = c[t] - c[e-1];

        cout << t1 << " " << t2 <<  " " << t3 << endl;
    }

}
