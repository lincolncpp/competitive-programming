#include <bits/stdc++.h>

using namespace std;

#define lg2(x) 31-__builtin_clz(x)

const int maxn = 1e5;
const int logmaxn = lg2(maxn);

int st[maxn+7][logmaxn+3] = {};

void build(const vector<int>&v){
    int n = (int)v.size();

    for(int i = 0;i < n;i++) st[i][0] = v[i];

    for(int j = 1;j <= logmaxn;j++){
        for(int i = 0;i+(1<<j) <= maxn+1;i++){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

// Range maximum query
int query(int l, int r){
    int j = lg2(r-l+1);
    return max(st[l][j], st[r-(1<<j)+1][j]);
}

int main(){

    vector<int>v = {10, 2, 3, 4, 5, 6};
    build(v);

    cout << query(1, 4) << endl;

    return 0;
}
