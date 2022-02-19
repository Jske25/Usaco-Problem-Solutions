#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string k; cin >> k;

    int counter = 0;
    for (int x = 0; x < k.size()-1; x++) {
        if (s.find(k.at(x)) < s.find(k.at(x+1))) {
            
        }
        else {
            counter++;
        }
    }
    counter++;

    cout << counter << endl;


}