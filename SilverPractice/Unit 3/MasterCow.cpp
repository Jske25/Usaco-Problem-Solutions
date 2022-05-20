#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<vector<int>>v (t, vector<int>(3));
    bool checker = true;
    for (int x = 0; x < t; x++) {
        for (int i = 0; i < 3; i++) {
            cin >> v[x][i];
        }
    }
    for (int x = 1000; x < 10000; x++) {
        string ok;
        bool exit = false;
        for (int i = 0; i < t; i++) {  
            ok = to_string(x);
            string temp = ok;
            int a = v[i][0], b = v[i][1], c = v[i][2];
            string s = to_string(a);
            int counterb = 0;
            for (int p = 0; p < ok.size(); p++) {
                if (ok[p] == s[p]) {
                    counterb++;
                    ok.erase(ok.begin() + p);
                    s.erase(s.begin() + p);
                    p--;

                }
            }
            if (counterb == b) {
                multiset<char> m;
                multiset<char> f;
                int counterc = 0;
                for (int q = 0; q < s.size(); q++) {
                    m.insert(s.at(q));
                }
                for (int q = 0; q < ok.size(); q++) {
                    f.insert(ok.at(q));
                }
                for (auto i : m) {
                    counterc += min(m.count(i), f.count(i));
                }
                if (counterc != c) {
                    exit = true;
                    break;
                }
                
            }
            else {
                exit = true;
                break;
            }
            ok = temp;
        }
        if (!exit) {
            checker = false;
            cout << ok << endl;
            break;
        }
    }
    if (checker) {
        cout << "NONE" << endl;
    }
}
