#include <bits/stdc++.h>
using namespace std;

#define s second
#define f first

bool cmp(pair<int, int> p, pair<int, int> t) {
    int t1 = p.f + p.s;
    int t2 = t.f + t.s;
    
    return t1 < t2;
}

int main() {
    int N, B; cin >> N >> B;
    vector<pair<int, int>> v;
    vector<pair<int, int>> t;
    
    for (int x = 0; x < N; x++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    int ans = 0;
    sort(v.begin(), v.end(), cmp);
    for (int x = 0; x < v.size(); x++) {
        int temp2 = v[x].f;
        v[x].f = v[x].f / 2;
        int ok = 0;
        int count = 0;
        int temp;
        for (int i = 0; i < v.size(); i++) {
            count = count + (v[i].f + v[i].s);
            if (count <= B) {
                temp = count;
                ok++;
            }
            else {
                count = temp;
                break;
            }
        }
        ans = max(ans, ok);
        
        v[x].f = temp2;
        
        
    }
    
    
    cout << ans << endl;
    
    
}
