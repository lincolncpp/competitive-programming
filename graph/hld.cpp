#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5;
vector<int>adj[maxn+7];
int parent[maxn+7] = {};
int depth[maxn+7] = {};
int heavy[maxn+7] = {};
int head[maxn+7] = {};
int pos[maxn+7] = {};
int curr_pos = 1;

int tree_query(int l, int r){
    return 0;
}

int dfs(int a){
    int size = 1;
    int max_csize = 0;

    for(int b:adj[a]){
        if (b == parent[a]) continue;
        parent[b] = a;
        depth[b] = depth[a]+1;

        int csize = dfs(b);
        size += csize;
        if (csize > max_csize){
            max_csize = csize;
            heavy[a] = b;
        }
    }

    return size;
}

void decompose(int a, int h){
    head[a] = h;
    pos[a] = curr_pos++;

    if (heavy[a] != 0) decompose(heavy[a], h);
    for(int b:adj[a]){
        if (b == heavy[a] || b == parent[a]) continue;
        decompose(b, b);
    }
}

// Max query
int query(int a, int b){
    int res = 0;

    while(head[a] != head[b]){
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, tree_query(pos[head[a]], pos[a]));
        a = parent[head[a]];
    }

    if (pos[a] > pos[b]) swap(a, b);
    res = max(res, tree_query(pos[a], pos[b]));

    return res;
}

int main(){

    dfs(1);
    decompose(1, 1);

    return 0;
}
