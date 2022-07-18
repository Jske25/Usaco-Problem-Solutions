#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a;
    vector<int> b;
    vector<bool> v(n, false);
    
    int largest = -1;
    int cnt = 0;
    
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        b.push_back(temp);
    }
    
    for (int x = 0; x < n; x++) {
        if (v[x] == true) {
            continue;
        }
        else {
            cnt++;
        }
        
        vector<int> temp;
        
        int i = x; int size = 0;
        
        while (v[i] != true) {
            v[i] = true;
            temp.push_back(a[i]);
            for (int j = 0; j < n; j++) {
                if (b[j] == a[i]) {
                    i = j;
                    size++;
                    break;

                    
                }
            }
        }
        
        if (size == 1) {
            cnt--;
        }
        
        largest = max(largest, size);
         
    }
    
    cout << ((largest==1)? 0:cnt) << " " << ((largest==1) ? -1:largest) << endl;
}
