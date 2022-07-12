#include <bits/stdc++.h>
using namespace std;

/*
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define mi map<int, int>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i <=b; ++i)
#define f first
#define s second

*/

#define int long long





void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int n;
int a[1000];

void Solve(int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = a[right];

    int i = left;
    int j = right-1;
    int temp;

    while (true) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;


    }

    temp = a[i];
    a[i] = a[right];
    a[right] = temp;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    Solve(left, i - 1);
    Solve(i+1, right);
    

    
}




signed main()
{
    setIO("");

    cin >> n;
    for (int x = 0; x < n; x++) {
        cin >> a[x];
    }
    Solve(0, n-1);

    

}
