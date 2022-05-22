#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(n);
    queue<int> q;
    while(!cin.eof()) {
        string c; int a; cin >> c >> a;

        if (c == "C") {
            q.push(a);
        }
        else if (c == "R") {
            v[a-1].push_back(q.front());
            q.pop();
        }
    }
    
    for (int x = 0; x < n; x++) {
        cout << v[x].size() << " ";
        for (int i = 0; i < v[x].size(); i++) {
            cout << v[x][i] << " ";
        }
        cout << endl;
    }
    
}
