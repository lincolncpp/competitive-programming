#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int bit[maxn+7] = {};

void update(int i, int val){
    while(i <= maxn){
        bit[i] = max(bit[i], val);
        i += i&(-i);
    }
}

int query(int i){
    int res = 0;
    while(i > 0){
        res = max(res, bit[i]);
        i -= i&(-i);
    }
    return res;
}

int main(){

    vector<int>vec(maxn);
    generate(vec.begin(), vec.end(), rand);

    // number compression
    map<int, int>ind;
    vector<int>v = vec;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for(int i = 0;i < (int)v.size();i++) ind[v[i]] = i+1;

    int lis[maxn+7] = {};
    int n = vec.size();
    for(int i = 0;i < n;i++){
        int val = ind[vec[i]];
        lis[i] = 1+query(val-1);
        update(val, lis[i]);
    }

    cout << "Length of the longest increasing subsequence" << endl;
    cout << query(vec.size()) << endl;

    return 0;
}
