#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "";
    string temp = "";
    string temp2;
    while (!cin.eof()) {
        getline(cin, temp);
        s = s + temp + '\n';
    }
    temp2 = s;
    vector<int> v;
    string check = "";
    for (int x = 0; x < s.size(); x++) {
        if ((s.at(x) <= 'z' && s.at(x) >= 'a') || (s.at(x) <= 'Z' && s.at(x) >= 'A')) {
            if (isupper(s.at(x))) {
                s.at(x) = s.at(x) + 32;
            }
            check = check + s.at(x);
            v.push_back(x);
        }
    }
    int anSize = 0;
    int a, b;
    for (int x = 0; x < check.size(); x++) {
        int L = x, R = x;
        while (check[L] == check[R]) {
            
            if (anSize < (R - L + 1)) {
                anSize = R - L + 1;
                a = L; 
                b = R;
            }
            R++; L--;
            if (R >= check.size() || L < 0) {
                break;
            }
        }
    }
    for (int x = 0; x < check.size()-1; x++) {
        int L = x; int R = x+1;
        while (check[L] == check[R]) {
            if (anSize < (R - L + 1)) {
                anSize = R - L + 1;
                a = L; 
                b = R;
            }
            R++; L--;
            if (R >= check.size() || L < 0) {
                break;
            }
        }
    }
    cout << anSize << endl;
    for (int x = v[a]; x <= v[b]; x++) {
        cout << temp2.at(x);
    }
}
