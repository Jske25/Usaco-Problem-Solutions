#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        string s; cin >> s;
        if (a%2 != 0) {
            cout << "illegal" << endl;
        }
        else {
            int counter1 = 0;
            int counter2 = 0;
            bool ok = true;
            for (int x = 0; x < s.size(); x++) {
                if (s.at(x) == '>') {
                    counter1++;
                }
                else {
                    counter2++;
                }
                if (counter2 > counter1) {
                    cout << "illegal" << endl;
                    ok = false;
                    break;
                }
            }
            if (counter2 == counter1 && ok) {
                cout << "legal" << endl;
            }
            
            else if (counter2 != counter1 && ok) {
                cout << "illegal" << endl;
            }
            
        }
    }
    
}
