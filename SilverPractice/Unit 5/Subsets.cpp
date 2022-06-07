#include <bits/stdc++.h>
using namespace std;

int arr[10];
int v[10];
int n;


void Subset(int position, int subsize, int limit) {
    if (subsize == limit) {
        for (int x = 0; x < n; x++) {
            if (arr[x] == 1) {
                cout << v[x];
            }
        }
        cout << endl;
        return;
    }
    else if (position == n) {
        return;
    }
    arr[position] = 1;
    Subset(position+1, subsize+1, limit);
    
    arr[position] = 0;
    Subset(position+1, subsize, limit);
    
}

int main() {
    cin >> n; 
    for (int x = 0; x < n; x++) {
        cin >> v[x];
    }
    for (int x = 1; x <= n; x++) {
        Subset(0, 0, x);
    }
}
