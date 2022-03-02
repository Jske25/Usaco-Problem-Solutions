#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    int n; cin >> n;
    set<char> d1;
    set<char> d2;
    set<char> d3;
    set<char> d4;
    bool ok = true;
    for (int x = 0; x < 6; x++) {
        char temp; cin >> temp;
        d1.insert(temp); //M O
    }
    for (int x = 0; x < 6; x++) {
        char temp; cin >> temp;
        d2.insert(temp);// O
    }
    for (int x = 0; x < 6; x++) {
        char temp; cin >> temp;
        d3.insert(temp); // A B C D E F
    }
    for (int x = 0; x < 6; x++) {
        char temp; cin >> temp;
        d4.insert(temp); // U V W X Y Z
    }
    
    for (int x = 0; x < n; x++) {
        multiset<char> s2;
        string s; cin >> s;
        for (int z = 0; z < s.size(); z++) {
            s2.insert(s.at(z));
        }
        
        for (char element : d1) {
            for (char element2 : d2) {
                for (char element3 : d3) {
                    for (char element4 : d4) {
                        ok = true;
                        multiset<char> f = {element, element2, element3, element4};
                        for (char elemento : s2) {
                            if ((f.count(elemento) < s2.count(elemento))) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }  
    }
}