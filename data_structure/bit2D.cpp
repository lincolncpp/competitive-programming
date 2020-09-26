#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+3;
int bit[maxn+11][maxn+11];

void updatej(int i, int j, int x){
    while(j <= maxn){
        bit[i][j] += x;
        j += j&(-j);
    }
}

void update(int i, int j, int x){
    while(i <= maxn){
        updatej(i, j, x);
        i += i&(-i);
    }
}

int queryj(int i, int j){
    int res = 0;

    while(j > 0){
        res += bit[i][j];
        j -= j&(-j);
    }

    return res;
}

int query(int i, int j){
    int res = 0;

    while(i > 0){
        res += queryj(i, j);
        i -= i&(-i);
    }

    return res;
}

int query(int ai, int aj, int bi, int bj){
    return query(bi, bj) - query(bi, aj-1) - query(ai-1, bj) + query(ai-1, aj-1);
}

int main(){



    return 0;
}
