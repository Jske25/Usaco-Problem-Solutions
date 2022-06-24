#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v = {1, 3, 7, 9};

void Subset(int num, int pos) {
    if (pos == n) {
        bool checker = true;
        for (int x = 2; x <= sqrt(num); x++) {
            if (num%x == 0) {
                checker = false;
                break;
            }
        }
        
        if (checker) {
            cout << num << endl;
        }
        else {
            return;
        }
    }
    bool ok = true;
    for (int x = 2; x <= sqrt(num); x++) {
        if (num%x == 0) {
            ok = false;
            return;
        }
    }
    if (ok) {
        for (int x = 0; x < v.size(); x++) {
            Subset(10*num + v[x], pos+1);
        }
    }
}

int main() {
    cin >> n;
    Subset(2, 1);
    Subset(3, 1);
    Subset(5, 1);
    Subset(7, 1);
    Subset(9, 1);
    
    
}
