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
    setIO("lazy");
    int n, k; cin >> n >> k;
    int ans = 0; 
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>>p(n+1, vector<int>(n+1, 0));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> v[x][y];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            p[i][y+1] = p[i][y] + v[i][y];
        }
    }
    for(int x = 0; x < n; x++) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int left = x-k;
            int right = x+k;
            int l = i;
            while (l >= 0 && left <= right) {
                sum+= p[l][min(right, n)] - p[l][max((long long)1, left)-1];
                l--; left++; right--;
            }
            left = x-k+1; right = x+k-1; int l2 = i+1;
            while (l2 <= n && left <= right) {
                sum+=p[l2][min(right, n)] - p[l2][max((long long)1, left) - 1];
                l2++; left++; right--;
            }
            ans = max(ans, sum);
        }

    }
    cout << ans << endl;

    
    
}
