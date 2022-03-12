#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string f; cin >> f;
    int duplicacy = 0;
    for (int x = 0; x < n-2; x++) {
        int counter_h = 0; int counter_g = 0;
        int a = x+3;
        for (int i = x; i <= x+2; i++) {
            if (f.at(i) == 'H') {
                counter_h++;
            }
            else {
                counter_g++;
            }
        }
        if (counter_g == 1 || counter_h == 1) {
            duplicacy++;
        }
        while (a <= n-1) {
            if (f.at(a) == 'H') {
                counter_h++;
            }
            else if (f.at(a) == 'G') {
                counter_g++;
            }
            if (counter_g == 1 || counter_h==1) {
                duplicacy++;
            }
            if (counter_g > 1 && counter_h > 1) {
               break;
            }
            a++; //change iteration
        }
    }

    cout << duplicacy << endl;
}
