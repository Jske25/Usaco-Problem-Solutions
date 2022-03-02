#include <bits/stdc++.h>
using namespace std;

bool Okay(vector<int> v, int i) {
    int sum =0;
    bool ok = true;
    for (int x = 0; x < v.size(); x++) {
        sum = sum + v.at(x);
        if (sum == i) {
            sum = 0;
            continue;
        }
        else if (sum > i) {
            ok = false;
            break;
        }
        else {
            continue;
        }        
    }
    return ok;
}


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = 0;
        bool check = false;
        int answer;
        vector<int> v(n);
        for (int x = 0; x < n; x++) {
            cin >> v[x];
            sum += v[x];
        }
        for (int x = n; x >=1; x--) {
            if (sum % x == 0) {
                if (Okay(v, (sum/x))) {
                    answer = x;
                    break;
                }

            }
        }
        cout << n - answer << endl;
        

    }


}