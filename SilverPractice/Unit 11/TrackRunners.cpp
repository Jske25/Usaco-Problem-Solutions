#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector<char> v;
vector<int> arr;
int start;

void Solve(int pos) {
    if (pos == n) {
        int counterV = 0;
        int counterC = 0;
        for (int x = 0; x < n; x++) {
            if (v[arr[x]] == 'a' || v[arr[x]] == 'e' || v[arr[x]] == 'i' || v[arr[x]] == 'o' || v[arr[x]] == 'u') {
                counterV++;
            }
            else {
                counterC++;
            }
        }
        if (counterV >= 1 && counterC >= 2) {
            string s = "";
            for (int x = 0; x < n; x++) {
                s = s + v[arr[x]];
            }
            cout << s << endl;
        }
        return;
    }
    if (pos == 0) {
        start = 0;
    }
    else {
        start = arr[pos-1]+1;
    }
    for (int i = start; i <= m-n+pos; i++) {
        arr[pos] = i;
        Solve(pos+1);
    }
}


int main() {
    cin >> n >> m;
    for (int x = 0; x < m; x++) {
        char c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    arr.resize(n);
    for (int x = 0; x < n; x++) {
        arr[x] = 0;
    }
    Solve(0);
    
    
    
    
    
}
