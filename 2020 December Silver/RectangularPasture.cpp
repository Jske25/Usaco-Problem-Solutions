#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define mi map<int, int>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i <=b; ++i)
#define f first
#define s second
#define int long long

const int MX = 2500;
int psum[MX+1][MX+1];


bool c(pii a, pii b) {
    return a.s < b.s;
}

long long pfSum(int x1, int y1, int x2, int y2)
{
    return (long long)(psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1]);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

signed main()
{
    setIO("");
    int n; cin >> n;
    vector<pair<int, int>> v(n);

    for (int x = 0; x < n; x++) {
        int a, b; cin >> a >> b;
        pii p = {a, b};
        v[x] = p;
    }
    sort(v.begin(), v.end());
    for (int x = 0; x < n; x++) {
        v[x].f = x+1;
    }
    sort(v.begin(), v.end(), c);
    for (int x = 0; x < n; x++) {
        v[x].s = x+1;
    }
    for (int x = 1; x <= n; x++) {
        psum[v[x-1].f][v[x-1].s] = 1;
    }
    for (int x = 1; x <= n; x++) {
        for (int i = 1; i <= n; i++) {
            psum[x][i]+= psum[x-1][i] + psum[x][i-1] - psum[x-1][i-1];
        }
    }

    long long ans = n + 1;

    for (int x = 0; x < n; x++) {
        for (int i = x+1; i < n; i++) {
            pii p = {v[x].f, v[x].s};
            pii z = {v[i].f, v[i].s};

            ans += pfSum(min(p.f, z.f), 1, max(p.f, z.f), min(p.s, z.s))*pfSum(min(p.f, z.f), max(p.s, z.s), max(p.f, z.f) , n);

        }
    }

    cout << ans << endl;
    
}
