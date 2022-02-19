#include <bits/stdc++.h>
using namespace std;

//2021 December Bronze Problem 3

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        int k; cin >> k;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        bool ok = true;
        bool check = true;
        bool third = true;
        bool fourth = true;
        vector<vector<char>> v (N, vector<char> (N, 0));
        for (int x = 0; x < N; x++) {
            for (int i = 0; i < N; i++) {
                cin >> v[x][i];
            }
        }
        // k = 1
        for (int x = 0; x < N-1; x++) {
            if (v[x][0] != '.') {
                ok = false;
                break;
            }
            if (v[N-1][x] !='.') {
                ok = false;
                break;
            }
        }
        for (int x = 0; x < N-1; x++) {
            if (v[0][x] != '.') {
                check = false;
                break;

            }
            if (v[x][N-1] !='.') {
                check = false;
                break;
            }
        }
        if (ok) {
            k1++;
        }
        if (check) {
            k1++;
        }
        //for k=2
        for (int x = 1; x < N-1; x++) {
            for (int i = 1; i <= x; i++) {
                if (v[i][0] !='.') {
                    third = false;
                    break;
                }
            }
            for (int i = 0; i < N; i++) {
                if (v[x][i] != '.') {
                    third = false;
                    break;
                }
            }
            for (int i = x; i < N; i++) {
                if (v[i][N-1] != '.') {
                    third = false;
                    break;
                }
            }
            if (third) {
                k2++;
            }
            third = true;
        }
        for (int x = 1; x < N-1; x++) {
            for (int i = 1; i <= x; i++) {
                if (v[0][i] !='.') {
                    third = false;
                    break;
                }
            }
            for (int i = 0; i < N; i++) {
                if (v[i][x] != '.') {
                    third = false;
                    break;
                }
            }
            for (int i = x; i < N; i++) {
                if (v[N-1][i] != '.') {
                    third = false;
                    break;
                }
            }
            if (third) {
                k2++;
            }
            third = true;
        }
        //for k = 3
        if (k ==3) {
            for (int x = 1; x < N-1; x++) {
                for (int y = 1; y < N-1; y++) {
                    for (int i = 1; i <= x; i++) {
                        if (v[i][0] != '.') {
                            fourth = false;
                            break;
                        }
                    }  
                    for (int i = 1; i <= y; i++) {
                        if (v[x][i] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    for (int z = x; z < N; z++) {
                        if (v[z][y] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    for (int i = y; i < N-1; i++) {
                        if (v[N-1][i] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    if (fourth) {
                        k3++;
                    }
                    fourth = true;
                }

            }
            //second
            for (int x = 1; x < N-1; x++) {
                for (int y = 1; y < N-1; y++) {
                    for (int i = 1; i <= x; i++) {
                        if (v[0][i] != '.') {
                            fourth = false;
                            break;
                        }
                    }  
                    for (int i = 1; i <= y; i++) {
                        if (v[i][x] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    for (int z = x; z < N; z++) {
                        if (v[y][z] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    for (int i = y; i < N; i++) {
                        if (v[i][N-1] != '.') {
                            fourth = false;
                            break;
                        }
                    }
                    if (fourth) {
                        k3++;
                    }
                    fourth = true;
                }
            }
        }


        if (k == 1) {
            cout << k1 << endl;
        }
        else if (k == 2) {
            cout <<  k1 + k2 << endl;
        }
        else {
            cout << k1 + k2 + k3 << endl;
        }
    }
}
