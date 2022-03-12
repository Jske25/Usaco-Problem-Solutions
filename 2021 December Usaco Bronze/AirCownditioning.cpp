#include <bits/stdc++.h>
using namespace std;

bool all_zero (vector<int> f) {
    bool sender = true;
    for (int x = 0; x < f.size(); x++) {
        if (f.at(x) != 0) {
            sender = false;
            break;
        }
    }

    return sender;
}

int main() {
    int n; cin >> n;
    vector<int> p;
    vector<int> t;
    vector<int> diff;
    int counter = 0;
    bool prev_zero = true; bool pos = false; bool neg = false;
    
    for (int x = 0; x < n; x++) {
        int tab; cin >> tab;
        p.push_back(tab);  
    }
    
    for (int x = 0; x < n; x++) {
        int tempVar; cin >> tempVar;
        t.push_back(tempVar);  
    }
    
    for (int x = 0; x < n; x++) {
        diff.push_back(p.at(x) - t.at(x));
    }
    
    while (!all_zero(diff)) {
            prev_zero = true;
            for (int x = 0; x < n; x++) {
                if (diff.at(x) == 0 || (diff.at(x) < 0 && pos == true) || (diff.at(x) > 0 && neg == true)) {
                    if (diff.at(x) == 0) {
                        pos = false;
                        neg = false;
                        prev_zero = true;
                        continue;

                    }
                    else if (pos) {
                        diff.at(x)++;
                        pos = false;
                        neg = true;
                        counter++;
                        prev_zero = false;
                    }
                    else if (neg) {
                        diff.at(x)--;
                        neg = false;
                        pos = true;
                        counter++;
                        prev_zero = false;
                    }
                }
                else if (diff.at(x) > 0) {
                    pos = true;
                    neg = false;
                    if (prev_zero) {
                        diff.at(x)--;
                        counter++;
                        prev_zero = false;
                    }
                    else {
                        diff.at(x)--;
                    }
                }
                else {
                    diff.at(x)++;
                    pos = false;
                    neg = true;
                    if (prev_zero) {
                        counter++;
                        prev_zero = false;
                    }
                }
            }   
    }

    cout << counter << endl;

}
