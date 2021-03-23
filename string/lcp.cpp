#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(nlogn)
    Query: O(1)
*/

#define lg2(x) 31-__builtin_clz(x)

const int maxn = 1e5;
const int logmaxn = lg2(maxn);

int len;
int pos[maxn+123];
int st[maxn+7][logmaxn+3] = {};

void build_sparse_table(const vector<int>&v){
    int n = (int)v.size();

    for(int i = 0;i < n;i++) st[i][0] = v[i];

    for(int j = 1;j <= logmaxn;j++){
        for(int i = 0;i+(1<<j) <= maxn+1;i++){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){
    if (l == r) return len-l;
    l = pos[l];
    r = pos[r];
    if (l > r) swap(l, r);
    r--;

    int j = lg2(r-l+1);
    return min(st[l][j], st[r-(1<<j)+1][j]);
}

vector<int> sort_cyclic(const string &s){
    int n = (int)s.size();
    int alpha = 256;

    vector<int>p(n), c(n), cnt(max(alpha, n));

    for(int i = 0;i < n;i++) cnt[s[i]]++;
    for(int i = 1;i < alpha;i++) cnt[i] += cnt[i-1];
    for(int i = n-1;i >= 0;i--) p[--cnt[s[i]]] = i;

    int classes = 1;
    c[p[0]] = 0;
    for(int i = 1;i < n;i++){
        if (s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes-1;
    }

    vector<int>pn(n), cn(n);
    for(int k = 0;(1<<k) < n;k++){
        fill(cnt.begin(), cnt.begin()+classes, 0);

        for(int i = 0;i < n;i++) pn[i] = (p[i]-(1<<k)+n)%n;
        for(int i = 0;i < n;i++) cnt[c[pn[i]]]++;
        for(int i = 1;i < classes;i++) cnt[i] += cnt[i-1];
        for(int i = n-1;i >= 0;i--) p[--cnt[c[pn[i]]]] = pn[i];

        classes = 1;
        cn[p[0]] = 0;
        for(int i = 1;i < n;i++){
            pair<int, int> a = {c[p[i]], c[(p[i]+(1<<k))%n]};
            pair<int, int> b = {c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
            if (a != b) classes++;
            cn[p[i]] = classes-1;
        }
        swap(c, cn);
    }

    return p;
}

vector<int> suffix_array(string s){
    s += '$';
    vector<int> sorted = sort_cyclic(s);
    sorted.erase(sorted.begin());
    return sorted;
}

vector<int> lcp_array(const string &s, const vector<int> &sa){
    int n = (int)s.size();

    vector<int> pi(n);
    for(int i = 0;i < n;i++) pi[sa[i]] = i;

    vector<int>lcp(n);
    int k = 0;
    for(int i = 0;i < n;i++){
        if (pi[i]+1 == n){
            k = 0;
            continue;
        }

        int j = sa[pi[i]+1];
        while(max(i+k, j+k) < n && s[i+k] == s[j+k]) k++;

        lcp[pi[i]] = k;
        if (k > 0) k--;
    }

    return lcp;
}

void build(string s){
    len = s.size();
    vector<int>sa = suffix_array(s);
    vector<int>lcp = lcp_array(s, sa);

    for(int i = 0;i < s.size();i++) pos[sa[i]] = i;

    build_sparse_table(lcp);
}

int main(){

    string s = "abab";
    build(s);

    cout << s << endl;
    for(int i = 0;i < s.size();i++){
        for(int j = i;j < s.size();j++){
            cout << "lcp(" << s.substr(i, 10) << ", " << s.substr(j, 10) << ") = " << query(i, j) << endl;
        }
    }

    return 0;
}
