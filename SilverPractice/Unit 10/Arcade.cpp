#include <bits/stdc++.h>
using namespace std;

int n; 
int marked[4] = {0, 0, 0, 0};
vector<int> ans;
int sum[4] = {0, 0, 0, 0};
int skills[12];
int best = INT_MAX;


void Subset(int pos) {
    if (pos == 12) {
        int max1 = 0;
        int mini = INT_MAX;
        for (int x = 0; x < 4; x++) {
            mini = min(mini, sum[x]);
            max1 = max(max1, sum[x]);
        }
        best = min(best, max1-mini);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (marked[i] < 3) {
            marked[i] += 1;
            sum[i] += skills[pos];
            Subset(pos + 1);
            marked[i] -= 1;
            sum[i] -= skills[pos];
        }
    }
    
    
}



int main() {
    for (int x = 0; x < 12; x++) {
        int temp; cin >> temp;
        skills[x] = temp;
    }
    Subset(0);
    
    cout << best << endl;
    
    
}
