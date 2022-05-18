#include <bits/stdc++.h>
using namespace std;

struct thing {
    int distance, row, column;
};

bool cmp(thing a, thing b) {
    if (a.distance < b.distance) {
        return true;
    }
    else if (a.distance == b.distance) {
        if (a.row < b.row) {
            return true;
        }
        else if (a.row == b.row && a.column < b.column) {
            return true;
        }
    }
    return false;
}

int main() {
    int w, r; cin >> w >> r;
    vector<vector<int>> v(r, vector<int>(w, 0));
    int middle = (w+1)/2;
    int row = 1;
    for (int x = 0; x < r; x++) {
        for (int i = 0; i < w; i++) {
            v[x][i] = pow((x+1-row), 2) + pow((i+1 - middle), 2);
        }
    }
    vector<thing> z;
    for (int x = 0; x < r; x++) {
        for (int i = 0; i < w; i++) {
            thing temp;
            temp.distance = v[x][i];
            temp.row = x+1;
            temp.column = i+1;
            z.push_back(temp);
        }
    }
    sort(z.begin(), z.end(), cmp);
    for (int x = 0; x < w*r; x++) {
        v[z[x].row-1][z[x].column-1] = x+1;
    }
    for (int x = r-1; x >= 0; x--) {
        for (int i = 0; i < w; i++) {
            cout << v[x][i] << " ";
        }
        cout << endl;
    }
    
}
