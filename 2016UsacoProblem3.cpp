#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int arr[26];


int main() {

    setIO("blocks");

    int N; cin >> N;
    for (int x = 0; x < N; x++) {
        string s, k; cin >> s >> k;
        int a1[26] = {0};
        int a2[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            a1[s.at(i)-97]++;

        }
        for (int y = 0; y < k.size(); y++) {
            a2[k.at(y)-97]++;

        }
        for (int f = 0; f < 26; f++) {
            arr[f] = arr[f] + max(a2[f], a1[f]);
        }
    }

    for (int x = 0; x < 26; x++) {
        cout << arr[x] << endl;
    }












    

}