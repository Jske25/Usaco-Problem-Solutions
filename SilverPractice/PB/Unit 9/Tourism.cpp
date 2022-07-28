#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x;
    vector<int> y;
    int total = 0;
    for (int t = 0; t < n; t++) {
        int a, b; cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    for (int i = 1; i< x.size(); i++) {
        total += abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    }
    int max1 = INT_MAX;
    for (int i = 1;  i <= n-2; i++) {
        int t1 = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        int t2 = abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]);
        int temp = total - t2 - t1 + abs(x[i+1] - x[i-1]) + abs(y[i+1] - y[i-1]);
        max1 = min(max1, temp);
    }
    
    cout << max1 << endl;
}
