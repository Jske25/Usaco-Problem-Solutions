#include <bits/stdc++.h>
using namespace std;

int main() {
       int n; cin >> n;
       vector<int> v(n+1, 0);
       for (int x = 1; x <= n; x++) {
           v[x] = x;
       }
       
       int pos = 1;
       int res;
       while (v[pos] > 0) {
           int temp = v[pos];
           v[pos] = 0;
           res = pos;
           
           if ((pos + temp)%n == 0) {
               pos = n;
           }
           else {
               pos = (pos + temp) % n;
           }
           
           
       }
       
       cout << res << endl;
}
