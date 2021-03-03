#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int link[maxn];
int siz[maxn];

int find(int x){
    while(x != link[x]){
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    link[b] = a;
    siz[a] += siz[b];
}

int main(){

    for(int i = 0;i < maxn;i++){
        link[i] = i;
        siz[i] = 1;
    }

    return 0;
}
