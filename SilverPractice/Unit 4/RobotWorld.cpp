#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    stack<int> s;
    int counterA = 1;
    for (int x = 0; x < n; x++) {
        string d; cin >> d;
        if (d == "ADD") {
            s.push(counterA);
            counterA++;
        }
        else {
            s.pop();
        }
        
    }
    cout << s.size() << endl;
    vector<int> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    
    for (int x = v.size()-1; x >= 0; x--){
        cout << v[x] << endl;
    }
    
}
