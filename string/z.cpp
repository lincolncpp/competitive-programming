#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(n)
*/

vector<int>z(const string &s){
    int n = (int)s.size();
    vector<int>v(n);

    int l, r;
    l = r = 0;
    for(int i = 1;i < n;i++){
        if (i <= r) v[i] = min(v[i-l], r-i+1);
        while(i+v[i] < n && s[i+v[i]] == s[v[i]]) v[i]++;
        if (i+v[i]-1 > r){
            l = i;
            r = i+v[i]-1;
        }
    }

    return v;
}

int main(){

    vector<int>v = z("aabxaabxay");

    for(int i = 0;i < v.size();i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
