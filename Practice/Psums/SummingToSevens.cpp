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
    setIO("div7");

   int n; cin >> n;
   vector<int> v(n+1, 0);
   for (int x = 1; x <= n; x++) {
    cin >> v[x];
    v[x] = v[x-1] + v[x];
    v[x] %= 7;
   }

   map<int, int> m;
   int max = 0;

   for (int x = 1; x <= n; x++) {
    if (m[v[x]] == 0) {
        m[v[x]] = x;
    }
    else {
        if (x - m[v[x]] > max) {
            max = x - m[v[x]];

        }
    }

   }

   cout << max << endl;






}
