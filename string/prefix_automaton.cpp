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

vector<vector<int>> automaton(string s){
    vector<vector<int>>res;

    s += '#';
    vector<int>pi = prefix(s);

    int n = (int)s.size();
    res.assign(n, vector<int>(26));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 26;j++){
            if (i > 0 && s[i] != 'a'+j) res[i][j] = res[pi[i-1]][j];
            else res[i][j] = i+('a'+j == s[i]);
        }
    }

    return res;
}

int main(){

    string p = "abacaba";
    vector<vector<int>>aut = automaton(p);

    string s = "ababxabacaba";
    int n = (int)s.size();
    int state = 0;
    for(int i = 0;i < n;i++){
        state = aut[state][s[i]-'a'];
        cout << state << " ";
    }
    cout << endl;

    return 0;
}
