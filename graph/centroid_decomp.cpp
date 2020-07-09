#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int n;
vector<int>adj[maxn+13];
int size[maxn+13] = {};
int dad[maxn+13] = {};
bool removed[maxn+13] = {};

void dfs(int a, int p){
    size[a] = 1;
    for(int b:adj[a]){
        if (b == p || removed[b]) continue;
        dfs(b, a);
        size[a] += size[b];
    }
}

int centroid(int a, int p, int m){
    for(int b:adj[a]){
        if (b == p || removed[b]) continue;
        if (size[b]*2 > m) return centroid(b, a, m);
    }
    return a;
}

void build(int a, int p){
    dfs(a, -1);
    a = centroid(a, -1, size[a]);
    dad[a] = p;
    removed[a] = true;

    for(int b:adj[a]){
        if (removed[b]) continue;
        build(b, a);
    }
}

int main(){

    cin>>n;
    for(int i = 0;i < n-1;i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    build(1, -1);

    return 0;
}
