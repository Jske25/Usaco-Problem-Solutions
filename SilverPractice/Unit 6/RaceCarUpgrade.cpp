#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<double, double, int> p, tuple<double, double, int> d) {
    return get<0>(p)/get<1>(p) > get<0>(d)/get<1>(d);
}



int main() {
    int F, M, N; cin >> F >> M >> N;
    vector<tuple<double, double, int>> v;
    vector<int> ans;
    for (int x = 0; x < N; x++) {
        int temp1, temp2; cin >> temp1 >> temp2;
        tuple<double, double, int> t = make_tuple(temp1, temp2, x+1);
        v.push_back(t);
    }

    
    
    sort(v.begin(), v.end(), cmp);


    double initial1 = F;
    double initial2 = M;
    for (int x = 0; x < v.size(); x++) {
        double temp1 = initial1 + get<0>(v[x]);
        double temp2 = initial2 + get<1>(v[x]);
        if (temp1/temp2 > initial1/initial2) {
            ans.push_back(get<2>(v[x]));
            initial1 = temp1;
            initial2 = temp2;
        }
    }
    sort(ans.begin(), ans.end());
    
    if (ans.size() == 0) {
        cout << "NONE" << endl;
    }
    else {
        for (int x = 0; x < ans.size(); x++) {
            cout << ans[x] << endl;
        }
    }
    
}
