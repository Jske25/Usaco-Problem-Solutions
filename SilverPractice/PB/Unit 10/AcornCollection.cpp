#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<string>> v(30);
    vector<vector<string>> q(n);
    int adj = 0;
    bool first = true;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < 4; i++) {
            string temp; cin >> temp;
        }
        
        int t = 0;
        while (true) {
            bool checker = true;
            
            string s; cin >> s;
            if (s == "acorn.") {
                first = false;
                break;
            }
            
            q[x].push_back(s);
            
            if (first) {
                adj++;
            }
            
            for (int l = 0; l < v[t].size(); l++) {
                if (s == v[t][l]) {
                    checker = false;
                    break;
                }
            }
            if (checker) {
                v[t].push_back(s);
            }
            t++;
        }
    }
    for (int x = 0; x < adj; x++) {
        sort(v[x].begin(), v[x].end());
    }
    
    vector<int> powers;
    for (int x = 0; x < adj; x++) {
        powers.push_back(v[x].size());
    }
    
    vector<int> dupe(adj);
    dupe[adj-1] = 1;
    for (int x = adj-2; x >= 0; x--) {
        dupe[x] = dupe[x+1] * powers[x+1];
    }
    
    int skip = 0;
    k--;
    
    vector<int> skipper;
    
    for (int x = 0; x < n; x++) {
        int counter = 0;
        for (int i = 0; i < q[x].size(); i++) {
            for (int t = 0; t < v[i].size(); t++) {
                if (v[i][t] == q[x][i]) {
                    counter += dupe[i] * t;
                    break;
                }
            }
        }
        skipper.push_back(counter);
        if (counter <= k) {
            skip++;
        }
    }
    
    sort(skipper.begin(), skipper.end());
    
    
    bool asf =  true;
    if (skip != 0) {
        k++;
        asf = false;
    }
    
    while (skip > 0) {
        int pos = lower_bound(skipper.begin(), skipper.end(), k) - skipper.begin();
       
        if (pos >= skipper.size() || skipper[pos] != k) {
            skip--;
            k++;
           
        }
        else if (skipper[pos] == k) {
            k++;

            continue;
        }
    }
    
    if (!asf) {
        k--;
    }



    int pow = k; 
    int r = k;
    
    
    for (int x = 0; x < adj; x++) {
        int r2 = r;
        pow = r2 / dupe[x];
        r = r2 % dupe[x];
        
        cout << v[x][pow] << " ";
        
    }
    cout << endl;
    
}
