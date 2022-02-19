#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if ((int)(name).size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }   
}

int main() {

    setIO("lostcow");

    int x, y; cin >> x >> y;

    int temp = y-x;

    int distance = 0;

    int starter = 0;

    int end = 1;

    bool once = true;

    int incrementor = 6;

    bool odd = true;


    while (!((temp > starter && temp <= end) || (temp < starter && temp >= end))) {
        distance += abs(end - starter);

        starter = end;

        if (once) {
            end = -2;
            once = false;
        }
        else {
            if (odd) {
                end += incrementor;
                incrementor = incrementor*2;
                odd = false;
            }
            else {
                end -= incrementor;
                incrementor = incrementor*2;
                odd = true;
            }
        }
    }

    distance+= abs(starter - temp);



    cout << distance << endl;


}
