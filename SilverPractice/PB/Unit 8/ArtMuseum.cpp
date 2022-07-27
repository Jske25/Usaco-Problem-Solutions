#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    vector<int> v;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    bool climb = true;
    for (int x = 0; x < v.size()-1; x++) {
        if (v[x+1] >= v[x]) climb = true;
        else if (v[x+1] < v[x] && climb == true) {
            climb = false;
            int left = 0;
            int right = n-1;
            for (int k= x-1; k >= 0; k--) {
                if (v[k+1] >= v[k]) continue;
                else {
                    left = k+1;
                    break;
                }
            }
            for (int k = x+1; k < n; k++) {
                if (v[k-1] >= v[k]) continue;
                else {
                    right = k-1;
                    break;
                }
            }
            ans = max(ans, (right-left+1));
            
        }
        int temp = 1;
        for (int k = n-1; k >= 1; k--) {
            if (v[k] >= v[k-1]) {
                temp++;
            }
            else {
                break;
            }
        }
        ans = max(ans, temp);
    }
    
    
    cout << ((ans==0)?n : ans) << endl;
}
