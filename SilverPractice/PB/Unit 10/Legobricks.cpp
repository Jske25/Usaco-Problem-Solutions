#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
int n, m; 
char c;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

void dfs(int a, int b) {
    for (int x = 0; x < 4; x++) {
        int aa = a + di[x];
        int bb = b + dj[x];
        if (aa < 0 || aa >= n || bb >= m || bb < 0 || v[aa][bb] != 'X') {
            continue;
        }
        
        v[aa][bb] = c;
        dfs(aa, bb);
    }
}

int main() {
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    for (int x = 0; x < n; x++)  {
        for (int i = 0; i < m; i++) {
            cin >> v[x][i];
        }
    }
    
    bool visited = true;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < m; i++) {
            if (v[x][i] == 'X') {
                if (visited) {
                    v[x][i] = '1';
                    c = '1';
                }
                else {
                    v[x][i] = '2';
                    c = '2';
                }
                dfs(x, i);
                visited = false;
            }
        }
    }
    int ans = INT_MAX;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < m; i++) {
            if (v[x][i] == '1') {
                for (int s = 0 ; s < n; s++) {
                    for (int p = 0; p < m; p++) {
                        if (v[s][p] == '2') {
                            int dist = abs(s-x) + abs(p-i);
                            ans = min(ans, dist);
                        }
                    }
                }
            }
        }
    }
    
    cout << ans-1 << endl;
}
