#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define MAXL 12

vector<int>adj[MAXN];
int nivel[MAXN];
int ancestor[MAXN][MAXL] = {};

void dfs(int a){
    for(auto b:adj[a]){
        nivel[b] = nivel[a]+1;
        ancestor[b][0] = a;
        dfs(b);
    }
}

int lca(int a, int b){
    if (nivel[a] < nivel[b]) swap(a, b);

    for(int i = MAXL-1;i >= 0;i--){
        if (nivel[a]-(1<<i) >= nivel[b]){
            a = ancestor[a][i];
        }
    }

    if (a == b) return a;

    for(int i = MAXL-1;i >= 0;i--){
        if (ancestor[a][i] != -1 && ancestor[a][i] != ancestor[b][i]){
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }

    return ancestor[a][0];
}

void build(){
    for(int i = 1;i <= MAXN;i++){
        for(int j = 0;j <= MAXL;j++){
            ancestor[i][j] = -1;
        }
    }

    nivel[1] = 0;
    dfs(1);

    for(int i = 1;i <= MAXN;i++){
        for(int j = 1;j < MAXL;j++){
            if (ancestor[i][j-1] == -1) continue;
            ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }
}

int main(){
    // Sample tree
    //
    //         1
    //       /  \
    //      2    3
    //     / \  / \
    //    4  5 6  7
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[3].push_back(7);

    build();

    cout << lca(3, 4) << endl;

    return 0;
}
