#include <bits/stdc++.h>

using namespace std;

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

vector<int> kmp(const string &s, const string &p, const vector<int>&pre){
    int n = (int)s.size();
    int m = (int)p.size();
    vector<int>res;

    int j = 0;
    for(int i = 0;i < n;i++){
        while(j > 0 && p[j] != s[i]) j = pre[j-1];
        if (p[j] == s[i]) j++;
        if (j == m) res.push_back(i-m+1);
    }

    return res;
}

int main(){

    string s = "yxabacabaxy";
    string p = "aba";
    vector<int>pre = prefix(p);
    vector<int>k = kmp(s, p, pre);

    for(int x:k) cout << x << endl;

    return 0;
}
