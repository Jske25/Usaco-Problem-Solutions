#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n; 

void merge(int left, int right) {
    int mid = left + (right - left)/2;
    int arr[right - left + 1];
    
    int L = left; int R = mid + 1; int k = 0;
    while (L <= mid && R <= right) {
        if (v[L] <= v[R]) {
            
            arr[k] = v[L];
            L++;
        }
        else {
            arr[k] = v[R];
            R++;
        }
        k++;
    }
    for (int i = L; i <= mid; i++) {
        arr[k] = v[i];
        k++;
    }
    for (int i = R; i <= right; i++) {
        arr[k] = v[i];
        k++;
    }
    for (int x = 0; x < right - left + 1; x++) {
        v[left + x] = arr[x];
    }
    for (int x = 0; x < v.size(); x++) {
        cout << v[x] << " ";
    }
    cout << endl;
    return;
    
}

void mSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left)/2;
    
    mSort(left, mid);
    mSort(mid+1, right);
    
    merge(left, right);
}



int main() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    mSort(0, v.size()-1);
    
}
