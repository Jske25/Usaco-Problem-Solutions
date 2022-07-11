#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int> v;
int ans = 0;

void merge(int left, int right) {
    int mid = left + (right-left)/2;
    int L = left; int R = mid+1;
    
    int length = right - left + 1;
    
    
    int arr[right - left + 1];
    
    if (v[L] <= v[R]) {
        for (int x = L; x <= mid; x++) {
            arr[x-L] = v[x];
        }
        for (int x = R; x <= right; x++) {
            arr[x - R + (mid - L + 1)] = v[x];
        }
        
        
    }
    else {
        
        for (int x = R; x <= right; x++) {
            arr[x-R] = v[x];
        }
        for (int x = L; x <= mid; x++) {
            arr[x - L + (right - R + 1)] = v[x];
        }
        
        ans += (length)*(length/2);
        
    }
    
    
    for (int x = left; x <= right; x++) {
        v[x] = arr[x-left];
    }
    
    
    
    return;
}

void Solve(int left, int right) {
    if (left >= right) {
       return;
    }
    
    int mid = left + (right - left)/2;
    
    Solve(left, mid);
    Solve(mid+1, right);
    
    merge(left, right);
    
    
}


int main() {
    cin >> n;
    for (int x = 0; x < pow(2, n); x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    Solve(0, v.size()-1);
    
    cout << ans << endl;
    
    for (int x = 0; x < v.size(); x++) {
        cout << v[x] << endl;
    }
    
    
    
    
    
}
