#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    vector<int> ans(n);
    vector<bool> visited(n, false);
    vector<int> t;
    
    map<int, int> mp;
    
    for (int x = 0; x < n; x++) {
        v[x] = x+1;
    }
    t = v;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        int mid = (b-a)/2;
        for (int x = 0; x <= mid; x++) {
            
            int temp = t[a+x];
            
            t[a+x] = t[b-x];
            t[b-x] = temp;
        }

    }
    
    for (int x = 0; x < v.size(); x++) {
        mp[v[x]] = t[x];
    }
    
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        vector<int> cycle;
        cycle.clear();
        
        vector<int> index;
        int pos = i;
        if (!visited[i]) {
            
            visited[pos] = true;
            cycle.push_back(v[pos]);
            index.push_back(pos);
            
            while (true) {
                pos = mp[v[pos]]-1;
                cycle.push_back(v[pos]);
                index.push_back(pos);
                visited[pos] = true;
                
                if (visited[mp[v[pos]] - 1]) break;

            }
            
            if (cycle.size() != 0) {
               int t2 = k % cycle.size();
               int pos = 0;
              
               
               
               for (int l = t2; l < cycle.size(); l++) {
                   ans[index[pos]] = cycle[l];
                   pos++;
               }
               for (int l = 0; l < t2; l++) {
                   ans[index[pos]] = cycle[l];
                   pos++;
               }
               
               
               
                
            }
            
            
        }
        
        
        
        
    
        
    }
    
    
    
    for (int x = 0; x < ans.size(); x++) {
        cout << ans[x] << endl;
    }
    
    
    
}
