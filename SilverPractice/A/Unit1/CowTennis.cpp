#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    int counter = 0;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int x = 0; x < n; x++) {
        for (int i = x+1; i < n; i++) {
            int UB = v[i] - v[x];
            int p1 = UB + v[i];
            int p2 = 2*UB + v[i];
            counter+= upper_bound(v.begin(), v.end(), p2) - lower_bound(v.begin(), v.end(), p1);
            
        }
    }
    cout << counter << endl;
}
