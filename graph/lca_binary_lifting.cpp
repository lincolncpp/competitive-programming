#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int maxl = 20;
int up[maxn+13][maxl+3] = {};
int dep[maxn+13] = {};
int timein[maxn+13] = {};
int timeout[maxn+13] = {};
vector<int>adj[maxn+13];
int curr_time = 0;

void dfs(int a, int p){
    timein[a] = curr_time++;
    dep[a] = dep[p]+1;

    up[a][0] = p;
    for(int i = 1;i <= maxl;i++){
        up[a][i] = up[up[a][i-1]][i-1];
    }

    for(int b:adj[a]){
        if (b == p) continue;
        dfs(b, a);
    }

    timeout[a] = curr_time++;
}

// Check if a is ancestor of b
bool is_ancestor(int a, int b){
    return timein[a] < timein[b] && timeout[a] > timeout[b];
}

int lca(int a, int b){
    if (a == b) return a;
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;

    for(int i = maxl;i >= 0;i--){
        if (!is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }

    return up[a][0];
}

int distance(int a, int b){
    return dep[a]+dep[b]-2*dep[lca(a, b)];
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

    dfs(1, 1);

    cout << lca(4, 3) << endl;
    cout << distance(4, 3) << endl;

    return 0;
}
