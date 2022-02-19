#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
    vector<vector<char>> v(3, vector<char> (3));
    vector<vector<char>> d(3, vector<char> (3));
    int yellow = 0;
    int green = 0;
    for (int x = 0; x < 26; x++) {
        arr[x] = 0;
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            char temp;
            cin >> temp;
            v[x][y] = temp;
            arr[temp - 65]++;
        }

    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cin >> d[x][y];
        }

    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (v[x][y] == d[x][y] || arr[d[x][y]] > 0) {
                arr[d[x][y]-65]--;
                green++;
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (v[x][y] != d[x][y] && arr[d[x][y]-65] > 0 ) {
                    yellow++;
                    arr[d[x][y]-65]--;
            }
        }
    }

    cout << green << endl;
    cout << yellow << endl;

}