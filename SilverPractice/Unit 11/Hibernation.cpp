#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int booler2 = INT_MAX;
int limit;
int a;
vector<int> v;
int arr[21];

void Solve(int pos) {
    if (pos == a) {
        int counter = 0;
        for (int x = 0; x < a; x++) {
            if (arr[x] == 1) {
                counter += v[x];
            }
        }
        if (counter < limit && limit - counter < booler2) {
            booler2 = limit - counter;
            ans = counter;
        }
        return;
    }
    arr[pos] = 0;
    Solve(pos+1);
    arr[pos] = 1;
    Solve(pos+1);
    
    
}

int main() {
    cin >> limit >> a;
    for (int x = 0; x < a; x++) {
       int temp; cin >> temp;
       v.push_back(temp);
    }
    Solve(0);
    
    cout << ans << endl;
    
    
}
