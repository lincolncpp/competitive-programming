#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define K 20

int st[N+7][K+3] = {};

int main(){

    vector<int>v = {8, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 7, 6, 5, 4, 3, 2, 1};
    int n = (int)v.size();

    // Range maximum query
    for(int i = 0;i < n;i++) st[i][0] = v[i];

    for(int j = 1;j <= K;j++){
        for(int i = 0;i+(1<<j) <= N;i++){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    int log[N+7] = {};
    log[1] = 0;
    for(int i = 2;i <= N;i++) log[i] = log[i/2]+1;

    int l = 0;
    int r = 7;

    int j = log[r-l+1];
    int query = max(st[l][j], st[r-(1<<j)+1][j]);

    cout << query << endl;

    return 0;
}
