#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v(5, vector<char>(5, 0));
vector<vector<bool>> vis(5, vector<bool>(5, false));

int di[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dj[8] = {0, 1, 0, -1, 1, 1, -1, -1};
string temp;
int ans = 0;
bool found = false;


void Solve(int row, int col, int pos) {
    if (found == true) {
        return;
    }
    
    if (pos == temp.size()) {
        ans++;
        found = true;
        return;
    }
    for (int x = 0; x < 8; x++) {
        int r = row + di[x];
        int c = col + dj[x];
        if (r >= 0 && r < 5 && c >= 0 && c < 5 && vis[r][c] == false && temp[pos] == v[r][c]) {
            vis[r][c] = true;
            Solve(r, c, pos+1);
            vis[r][c] = false;
        }
    }
}


int main() {
    for (int x = 0; x < 5; x++) {
        for (int i = 0; i < 5; i++) {
            cin >> v[x][i];
        }
    }
    while(!cin.eof()) {
        string s; cin >> s;
        found = false;
        for (int x = 0; x < 5; x++) {
            for (int i = 0; i < 5; i++) {
                if (found == false) {
                    if (s[0] == v[x][i]) {
                        temp = s;
                        vis[x][i] = true;
                        Solve(x, i, 1);
                        vis[x][i] = false;
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    
}
