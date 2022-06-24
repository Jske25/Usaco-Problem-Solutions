#include <bits/stdc++.h>
using namespace std;

string s; 
int ans = 0;

void recursion(int pos) {
    if (pos == s.size()-1) {
        ans++;
        return;
    }
    else if (pos >= s.size()) {
        return;
    }
    if (s[pos] == '#') {
        return;
    }
    recursion(pos+2);
    recursion(pos+1);
}



int main() {
    cin >> s;
    recursion(0);
    
    cout << ans << endl;
    
    
    
}
