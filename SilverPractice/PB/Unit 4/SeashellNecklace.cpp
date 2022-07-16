#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<char>> v;
string s = "";
int ans = 0;
int cnt, res = 0;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    if (2*cnt == s.size()) {
        return false;
    }
    char ch = v[x][y];
    
    if (ch == '<' && s[s.size()-1] == '>') {
        return false;
    }
    
    if (ch == '>' && 2*cnt <= s.size()) {
        return false;
    }
    
    return true;
    
}



void dfs(int x, int y) {
    if (cnt*2 == s.size()) {
        res = max(res, (int)s.size()) ;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        
        int xx = x + di[i];
        int yy = y + dj[i];
        
        if (xx < 0 || xx >= n || yy < 0 || yy >= n || v[xx][yy] == '.') {
            continue;
        }
        
        if (isValid(xx, yy)) {
            s += v[xx][yy];
        
            char temp = v[xx][yy];
        
            v[xx][yy] = '.';
            
            if (temp == '<') {
                cnt++;
            } 
        
            dfs(xx, yy);
            
            if (temp == '<') {
                cnt--;
            }
            
            s.pop_back();
            
            v[xx][yy] = temp;
        }
        
    }
}


int main() {
    cin >> n; 
    v.resize(n, vector<char>(n));
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < n; i++) {
            cin >> v[x][i];
        }
    }
    if (v[0][0] == '<') {
        s += '<';
        v[0][0] = '.'; //super important, change visited boolean for first position
        cnt++;
        dfs(0, 0);
    }
    
    cout << res << endl;
}
