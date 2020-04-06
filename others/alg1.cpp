#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int>v = {1, 2, 3, 4, 3, 2, 1};
    int n = (int)v.size();

    vector<int>left(n);
    for(int i = 0;i < n;i++){
        left[i] = i-1;
        while(left[i] >= 0 && v[i] >= v[left[i]]) left[i] = left[left[i]];
    }

    vector<int>right(n);
    for(int i = n-1;i >= 0;i--){
        right[i] = i+1;
        while(right[i] < n && v[i] >= v[right[i]]) right[i] = right[right[i]];
    }

    for(int x:v) cout << x << " ";
    cout << endl;

    cout << "left:" << endl;
    for(int l:left) cout << l << " " ;
    cout << endl;

    cout << "right" << endl;
    for(int r:right) cout << r << " ";
    cout << endl;

    return 0;
}
