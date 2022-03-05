#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


bool checker(string s, int x) {
    multiset<string> f;
    bool ok = true;
    for (int i = 0; i < s.size()-x+1; i++) {
        string t = "";
        for (int z = i; z < i+x; z++) {
            t = t + s.at(z);
        }
        if (f.count(t) > 0) {
            ok = false;
            break;
        }
        else{
            f.insert(t);
        }
    }
    return ok;


}

int main() {

    setIO("whereami");
    ios::sync_with_stdio(false);
	cin.tie(0);



    int n; cin >> n;
    string s; cin >> s;
    int ans;
    for (int x = 1; x < n; x++) {
        if(checker(s,x)) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
    
}
