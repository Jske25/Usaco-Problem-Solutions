#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    string s; cin >> s;
    int n; cin >> n;
    int len = s.size();
    while (len < n) {
        len = len*2;
    }
    n--;
    while (len > s.size()) {
        if (n > len/2  ) {
            n = n-(len/2)-1;
        }
        else if (n == len/2 ) {
            n = n-1;
        }
        len /= 2;
    }
    
    cout << s[n] << endl;
    
}
