#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}


vector<int> v;

void switcher(vector<int> & a) {
    vector<int> n(a.size());
    for (int x = 0; x < a.size(); x++) {
        n[v.at(x)-1] = a.at(x);
    }
    a = n;
}



int main() {

    setIO("shuffle");

    int N; cin >> N;
    v.resize(N);

    vector<int> a(N);
    for (int x = 0; x < N; x++) {
        a[x] = x;
    }

    for (int x = 0; x < N; x++) {
        cin >> v[x];
    }

    for (int x = 0; x < 3; x++) {
        switcher(a);
    }
 
    vector<pair<int, int>> d(N);

    for (int x = 0; x < N; x++) {
        int temp; cin >> temp;
        pair<int, int> p = {a[x]+1, temp};
        d[x] = p;
    }
    sort(d.begin(), d.end());
    for (auto i : d) {
        cout << i.second << endl;
    }
  


}
