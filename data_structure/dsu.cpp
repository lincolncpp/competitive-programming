#include <bits/stdc++.h>

using namespace std;

#define N 100000

int link[N];
int siz[N];

int find(int x){
    while(x != link[x]) x = link[x];
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b]) swap(a, b);
    link[b] = a;
    siz[a] += siz[b];
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){

    for(int i = 0;i < N;i++){
        link[i] = i;
        siz[i] = 1;
    }

    return 0;
}
