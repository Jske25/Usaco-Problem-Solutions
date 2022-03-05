#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}



int main() {

    setIO("nostlast");
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    map<string, int> m;
    m["Bessie"] = 0, m["Elsie"] = 0, m["Daisy"] = 0, m["Gertie"] = 0, m["Annabelle"] = 0, m["Maggie"] = 0, m["Henrietta"] = 0;
    for (int x = 0; x < n; x++) {
        string s; cin >> s;
        int t; cin >> t;
        m[s] = m[s] + t;
    }
    vector<pair<int, string>> v;
    v.push_back({m["Bessie"],"Bessie"});
    v.push_back({m["Elsie"],"Elsie"});
    v.push_back({m["Daisy"],"Daisy"});
    v.push_back({m["Gertie"],"Gertie"});
    v.push_back({m["Annabelle"],"Annabelle"});
    v.push_back({m["Maggie"],"Maggie"});
    v.push_back({m["Henrietta"],"Henrietta"});

    sort(v.begin(), v.end());
    string ans;
    int counter;
    int numero = 0;

    for (int x = 0; x < v.size(); x++) {
        if (v.at(x).first > v.at(0).first) {
            int counter = v.at(x).first;
            ans = v.at(x).second;
            break;
        }
    }
    for (int x = 0; x < v.size(); x++) {
        if (v.at(x).first == counter) {
            numero++;
        }
    }
    if (numero > 1 || (v.at(0).first == v.at(v.size()-1).first)) {
        cout << "Tie" << endl;
    }
    else {
        cout << ans << endl;
    }
    
}
