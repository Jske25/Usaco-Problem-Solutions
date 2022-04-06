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

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

signed main()
{
    setIO("paintbarn");
    
    int n, k; cin >> n >> k;
    vector<vector<int>> v(1001, vector<int>(1001, 0));
    vector<vector<int>> psum(1001, vector<int>(1001, 0));
    int counter = 0;
    for (int x = 0; x < n; x++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v[a+1][b+1]++;
        v[c+1][d+1]++;
        v[c+1][b+1]--;
        v[a+1][d+1]--;
    }
    for (int x = 1; x <= 1000; x++) {
        for (int i = 1; i <= 1000; i++) {
            psum[x][i] = v[x][i] + psum[x-1][i] + psum[x][i-1] - psum[x-1][i-1];

        }
    }
    for (int x = 1; x <= 1000; x++) {
        for (int i = 1; i <= 1000; i++) {
            if (psum[x][i] == k) {
                counter++;
            }

        }
    } 
    cout << counter << endl;



    
}
