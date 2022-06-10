#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
vector<int> v;
int arr[MX];


int m, n;

void Subset(int pos) {
    if (pos == n) {
        for (int x = 0; x < n; x++) {
            cout << v[arr[x]];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        arr[pos] = i;
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
