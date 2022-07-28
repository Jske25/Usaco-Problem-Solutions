#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int ans;
    bool found = false;
    char g[3] = {'0', '1', '2'};
    
    for (int x = 0; x < a.size(); x++) {
        for (int i = 0; i < b.size(); i++) {
            char t1 = a[x];
            char t2 = b[i];
            if (a[x] == '1') {
                a[x] = '0';
            }
            else {
                a[x] = '1';
            }


            for (int yy = 0; yy < 3; yy++) {
                if (g[yy] == t2) {
                    continue;
                }

                b[i] = g[yy];
                
                int pot = 1;
                int pot2 = 1;
                int c1 = 0;
                int c2 = 0;
                
                for (int f = a.size()-1; f >= 0; f--) {
                    c1 += (a[f] - '0')*pot;
                    pot = pot * 2;
                }
                for (int f = b.size()-1; f >= 0; f--) {
                    c2 += (b[f] - '0')*pot2;
                    pot2 = pot2 * 3;
                }
                if (c2 == c1) {
                    ans = c2;
                    
                    found = true;
                    break;
                }
                    
                
                
                b[i] = t2;
                
                
            }


            if (found) {
                break;
            }

            b[i] = t2;
            a[x] = t1;
            
            
            
            
            
        }
        
        if (found) {
            break;
        }
        
        
        
    }
    
    
    cout << ans << endl;
    
}
