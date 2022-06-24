#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[16];
int ans = 0;

void Subset(int pos, int zero, int one) {
    if (pos == n) {
        if (one > zero) {
            ans++;
            for (int x = 0; x < n; x++) {
                cout << arr[x];
            }
            cout << endl;
            return;
        }
        else {
            return;
        }
    }
    arr[pos] = 0;
    Subset(pos+1, zero+1, one);
    arr[pos] = 1;
    Subset(pos+1, zero, one+1);
}

int main() {
    cin >> n;
    Subset(0, 0, 0);
    cout << ans << endl;
    
}
