#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> v;
const int MX = 1e5;
int arr[MX];
vector<bool> b;

void Subset(int pos) {
    if (pos == n) {
        for (int x = 0; x < n; x++) {
            cout << v[arr[x]];
        }
        cout << endl;
        return;
    }
    for (int x = 0; x < m; x++) {
        if (b[x] == false) {
            b[x] = true;
            arr[pos] = x;
            Subset(pos+1);
            b[x] = false;
        }
    }
    
}

int main() {
    cin >> m;
    for (int x = 0; x < m; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
        b.push_back(false);
    }
    cin >> n;
    Subset(0);
    
    
}
