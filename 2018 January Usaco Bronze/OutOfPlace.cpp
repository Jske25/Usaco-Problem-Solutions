#include <bits/stdc++.h>
using namespace std;

void Swap (vector<int>& v, int a, int b) {
    int temp = v.at(a);
    v.at(a) = v.at(b);
    v.at(b) = temp; 
}

bool sorted(vector<int> v) {
    bool ok = true;
    for (int x = 0; x < v.size()-1; x++) {
        if (v.at(x) < v.at(x+1)) {
            continue;
        }
        else {
            ok = false;

        }
    }
    return ok;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}



int main() {

    setIO("outofplace");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for (int x = 0 ; x < n; x++) {
        cin >> v[x];
    }
    int ans = 0;
    vector<int> d = v;
    sort(d.begin(), d.end());
    for (int x = 0; x < v.size(); x++) {
        if (d[x] != v[x]) {
            ans++;
        }
    }
    cout << max(0, ans-1);
}
