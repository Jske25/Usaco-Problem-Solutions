#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[15];
vector<tuple<int, int, int>> v;
int ans = 0;

void Subset(int pos) {
    if (pos == N) {
        for (int i = 0; i < v.size(); i++) {
            if (get<2>(v[i]) == -1) {
                if (arr[get<1>(v[i])-1] == arr[get<0>(v[i])-1]) {
                    return;
                }
            }
            else {
                if (arr[get<1>(v[i])-1] != arr[get<0>(v[i])-1]) {
                    return;
                }
            }
        }
        ans++;
        return;
        
    }
    for (int x = 0; x < 3; x++) {
        arr[pos] = x;
        Subset(pos+1);
    }
}


int main() {
    cin >> N >> K;
    for (int x = 0; x < K; x++) {
        char c; int a, b; cin >> c >> a >> b;
        if (c == 'S') {
            tuple<int, int, int>t = make_tuple(a, b, 1);
            v.push_back(t);
        }
        else {
            tuple<int, int, int>t = make_tuple(a, b, -1);
            v.push_back(t);
        }
        
    }
    Subset(0);
    cout << ans << endl;
    
}
