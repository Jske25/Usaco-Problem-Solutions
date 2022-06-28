#include <bits/stdc++.h>
using namespace std;

const int MX = 2e4+1;
int arr[MX];
int ans = 0;

int main() {
    int n, t; cin >> n >> t;
    vector<int> v(n);
    vector<int> checker;
    for (int x = 0; x < n; x++) {
        cin >> v[x];
        v[x] = 2*v[x];
        arr[v[x]]++;
    }
    sort(v.begin(), v.end());
    for (int x = 0; x < v.size()-1; x++) {
        int temp = v[x] + v[x+1];
        checker.push_back((temp)/2);
    }
    for (int x = 1; x < v.size()-1; x++) {
        checker.push_back(v[x]);
    }
    
    
    sort(checker.begin(), checker.end());
    
    
    for (int x = 0; x < checker.size(); x++) {
        int L = checker[x]-1;
        int R = checker[x]+1;
        bool violation = false;
        while (L >= 0 && R <= 2*t) {
            if (arr[L] != arr[R]) {
                violation = true;
                break;
            }
            L--;
            R++;
        }
        if (violation == false) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
}
