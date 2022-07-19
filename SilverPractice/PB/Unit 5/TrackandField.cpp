#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1001;
int a[MAXN]; int b[MAXN]; int v[MAXN][MAXN];

int ft[MAXN], state[MAXN];
const int WAITING = 0, RUNNING = 1, FINISHED = 2;


int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        cin >> a[x] >> b[x];
        for (int i = 0; i < b[x]; i++) {
            cin >> v[x][i];
            v[x][i]--;
            
        }
    }
    
    for (int x = 0; x < n; x++) {
        state[x] = WAITING;
    }
    
    ft[0] = a[0];
    state[0] = RUNNING;
    
    for (int x = 0; x < n; x++) {
        int finisher = -1;
        for (int i = 0; i < n; i++) {
            if (state[i] == RUNNING && (finisher == -1 || ft[i] < ft[finisher] )) {
                finisher = i;
            }
        }
        
        state[finisher] = FINISHED;
        
        
        for (int i = 0; i < b[finisher]; i++) {
            
            int other = v[finisher][i];
            
            
            if (state[other] == WAITING) {
                
                state[other] = RUNNING;
                ft[other] = a[other] + ft[finisher];
            }
        }
    }
    
    int last = 0;
    
    for (int x = 0; x < n; x++) {
        last = max(last, ft[x]);
        
    }
    
    cout << last << endl;
    
    
}
