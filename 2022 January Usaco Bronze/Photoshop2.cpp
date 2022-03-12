#include <bits/stdc++.h>
using namespace std;

int counter = 0;

bool Finder(vector<int> v, int i) {
    bool ok = false;
    for (int x = 0; x < v.size(); x++) {
        if (v.at(x) == i) {
            ok = true;
        }
    }
    return ok;
}

void Recursion(vector<int>& v, int i) {
    for (int x = v.size()-1; x >= 0; x--) {
        if (v.at(x) != i) {
            counter++;
            v.pop_back();
        }
        else if (v.at(x) == i){
            v.pop_back();
            break;
        }
    }

}

int main() {
    int n; cin >> n;
    vector<int> v;
    vector<int> sorted(n);
    vector<int> difference;
    for (int x = 0; x < n; x++) {
        int temp;  cin >> temp;
        v.push_back(temp);
    }
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        sorted[temp-1] = x;
    }
    for (int x = 0; x < n; x++) {
        v.at(x) = sorted[v.at(x)-1]+1;
    }

    for (int x = n; x >= 1; x--) {
        if (Finder(v, x)) {
            Recursion(v, x);
        }
    }
    cout << counter << endl;

}
