#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    stack<pair<int, int>> stk;
    vector<pair<int, int>> v;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back({temp, x});
    } 
    vector<int> t(n, 0);
    stk.push(v[0]);
    for (int x = 1; x < v.size(); x++) {
        while(!(stk.top().first >= v[x].first)) {
            
            t[stk.top().second] = x+1;
            stk.pop();
            if (stk.empty()) {
                break;
            }
        }
        stk.push(v[x]);
    }

    for (int x = 0; x < t.size(); x++) {
        cout << t[x] << endl;
    }

}
