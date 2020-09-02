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

    vector<int>v(maxn);
    generate(v.begin(), v.end(), rand);

    map<int, int>f;
    int curr = 1;
    vector<int>vsorted = v;
    sort(vsorted.begin(), vsorted.end());
    for(int x:vsorted){
        if (f[x] == 0) f[x] = curr++;
    }

    for(int x:v) update(f[x], 1+query(f[x]-1));

    cout << "Length of the longest increasing subsequence" << endl;
    cout << query(curr) << endl;

    return 0;
}
