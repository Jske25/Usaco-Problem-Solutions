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

    setIO("cownomics");

    int n; cin >> n; 
    int k; cin >> k;
    bool ok = true;

    vector<string> spotty(n);
    vector<string> plain(n);

    for (int x = 0; x < n; x++) {
        cin >> spotty[x];
    }
    for (int x = 0; x < n; x++) {
        cin >> plain[x];
    }

    string s(3, '0');
    set<string> counter;
    int answer = 0;

    for (int i = 0; i < k; i++) {
        for (int z = i+1; z < k; z++) {
            for (int x = z+1; x < k; x++) {
                counter.clear();
                ok = true;
                for (int f = 0; f < n; f++) {
                    s[0] = spotty[f][i]; s[1] = spotty[f][z]; s[2] = spotty[f][x];
                    counter.insert(s);
                }

                for (int f = 0; f < n; f++) {
                    s[0] = plain[f][i]; s[1] = plain[f][z]; s[2] = plain[f][x];
                    if (counter.count(s)) {
                        ok = false;
                        break;
                    }

                }

                if (ok) {
                    answer++;

                }
            }
        }
    }

    cout << answer << endl;



    

}
