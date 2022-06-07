#include <bits/stdc++.h>
using namespace std;


int main() {
    int s; cin >> s;
    vector<int> L;
    vector<int> R;
    
    int counter = 1;
    
    for (int x = 0; x < s; x++) {
        char A, B; cin >> A >> B;
        if (A == 'A') {
            if (B == 'L') {
                L.push_back(counter);
                counter++;
            }
            else {
                R.push_back(counter);
                counter++;
            }
        }
        else {
            int n; cin >> n;
            if (B == 'R') {
                int temp = n;
                for (int i = 0; i < n; i++) {
                    R.pop_back();
                    temp--;
                    if (R.empty()) {
                        break;
                    }
                }
                if (temp != 0) {
                    L.erase(L.begin(), L.begin() + temp);
                }
            }
            else {
                int temp = n;
                for (int i = 0; i < n; i++) {
                    L.pop_back();
                    temp--;
                    if (L.empty()) {
                        break;
                    }
                }
                if (temp != 0) {
                    R.erase(R.begin(), R.begin() + temp);
                }
                
            }
            
        }
    }
    
    for (int x = L.size()-1; x>= 0; x--) {
        cout << L[x] << endl;
    }
    for (int i = 0; i < R.size(); i++) {
        cout << R[i] << endl;
    }
    
    
}
