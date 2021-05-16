#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(n)
*/

vector<int> prefix(const string &s){
    int n = (int)s.size();
    vector<int>p(n);

    for(int i = 1;i < n;i++){
        p[i] = p[i-1];
        while(p[i] > 0 && s[p[i]] != s[i]) p[i] = p[p[i]-1];
        if (s[p[i]] == s[i]) p[i]++;
    }

    return p;
}

int main(){

    vector<int>p = prefix("aabxaabxay");

    for(int i = 0;i < p.size();i++) cout << p[i] << " ";
    cout << endl;

    return 0;
}
