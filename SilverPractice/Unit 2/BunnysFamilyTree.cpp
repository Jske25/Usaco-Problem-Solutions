#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, f; cin >> m >> f;
    vector<vector<int>> v(m, vector<int>(f, 0));
    vector<string> male;
    vector<string> female;
    for (int x = 0; x < m; x++) {
        string s; cin >> s;
        male.push_back(s);
    }
    for (int x = 0; x < f; x++) {
        string s; cin >> s;
        female.push_back(s);
    }
    for (int x = 0; x < m; x++) {
        for (int i = 0; i < f; i++) {
            bool checker = true;
            for (int z = 0; z < m; z++) {
                if (z != x) {
                    for (int t = 0; t < 25; t++) {
                        if (male[z][t] != female[i][t] && male[z][t] != male[x][t]) {
                            checker = false;
                            break;
                        }
                    }
                    if (checker) {
                        v[x][i]++;
                    }
                    
                    checker = true;
                }
                checker = true;
            }
            for (int z = 0; z < f; z++) {
                if (z != i) {
                    for (int t = 0; t < 25; t++) {
                        if (female[z][t] != female[i][t] && female[z][t] != male[x][t]) {
                            checker = false;
                            break;
                        }
                    }
                    if (checker) {
                        v[x][i]++;
                    }
                    checker = true;
                }
            }
            checker = true;
            
        }
    }
    for (int x = 0; x < m; x++) {
        for (int i = 0; i < f; i++) {
            cout << v[x][i] << " ";
        }
        cout << endl;
    }
    
}
