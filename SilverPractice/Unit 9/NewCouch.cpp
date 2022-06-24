#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20];
vector<int> v;
int ans = 0;

bool isok(int x, int y) {
    while (x > 0 && y > 0) {
        if (x%10 + y%10 >= 10) {
            return false;
        }
        else {
            x /= 10;
            y /= 10;
        }
    }
    return true;
}

void Subset(int pos, int totalones, int currsum) {
    if (pos == n) {
        ans = max(ans, totalones);
        return;
    }
    Subset(pos+1, totalones, currsum);
    if (isok(currsum, v[pos])) {
        Subset(pos+1, totalones+1, currsum+v[pos]);
    }
    
}



int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    Subset(0, 0, 0);
    cout << ans << endl;
    
    
    
}
