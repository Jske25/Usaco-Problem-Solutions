#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> v;
const int MX = 1e5;
int arr[MX];
int start;

void Subset(int pos) {
    if (pos == n) {
        for (int x = 0; x < n; x++) {
            cout << v[arr[x]];
        }
        cout << endl;
        return;
    }
    if (pos == 0) {
        start = 0;
    }
    else {
        start = arr[pos-1]+1;
    }
    for (int x = start; x <= m-n+pos ; x++) {
        arr[pos] = x;
        Subset(pos+1);
    }
    
}

int main() {
    cin >> m;
    for (int x = 0; x < m; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    cin >> n;
    Subset(0);
    
    
}
