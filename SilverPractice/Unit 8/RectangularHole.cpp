#include <bits/stdc++.h>
using namespace std;

int n, b; 
const int MX = 1e5;
int arr[MX];
vector<int> v;
int ans = INT_MAX;

void Subsum(int pos, int m) {
    if (pos == m) {
        int counter = 0;
        for (int x = 0; x < m; x++) {
            counter += v[arr[x]];
        }
        if (counter - b < 0) {
            return;
        }
        else {
            ans = min(ans, counter - b);
            return;
        }
    }
    int start;
    if (pos == 0) {
        start = 0;
    }
    else {
        start = arr[pos-1] + 1;
    }
    for (int x = start; x <= n - m + pos; x++) {
        arr[pos] = x;
        Subsum(pos+1, m);
    }
    
}

int main() {
    cin >> n >> b;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    for (int m = 1; m <= n; m++) {
        Subsum(0, m);
    }
    
    cout << ans << endl;
    
    
    
}
