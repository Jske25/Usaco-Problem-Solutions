#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int g;
vector<vector<int>> p;
int arr[15];
int best = INT_MAX;
vector<int> ans;


void Subset(int pos, int ones) {
    if (pos == g) {
        vector<int> temp(n, 0);
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < g; i++) {
                if (arr[i] == 1) {
                    temp[x]+= p[i][x];
                }
            }
        }
        bool violation = false;
        for (int x = 0; x < n; x++) {
            if (temp[x] < v[x]) {
                violation = true;
            }
        }
        if (violation == false && ones < best) {
            best = ones;
            vector<int> t2;
            for (int i = 0; i < g; i++) {
                if (arr[i] == 1) {
                    t2.push_back(i+1);
                }
            }
            ans = t2;
        }
        return;
        
    }
    arr[pos] = 1;
    Subset(pos+1, ones+1);
    arr[pos] = 0;
    Subset(pos+1, ones);
}

int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    
    cin >> g;
    
    p.resize(g, vector<int>(n, 0));
    
    for (int x = 0; x < g; x++) {
        for (int i = 0; i < n; i++)  {
            int temp; cin >> temp;
            p[x][i] = temp;
        }
    }
    Subset(0, 0);
    
    cout << best << " ";
    for (int x = 0; x < ans.size(); x++) {
        cout << ans[x] << " ";
    }
    cout << endl;
    
    
}
