#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(nlogn)
*/

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

int main(){

    for(int i:suffix_array("caule")) cout << i << " ";
    cout << endl;

    return 0;
}
