#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
vector<int>adj[maxn+11];
vector<int>radj[maxn+11];
bool vis[maxn+11] = {};
vector<int>order, comp;

void dfs1(int a){
    if (vis[a]) return;
    vis[a] = true;
    for(int b:adj[a]) dfs1(b);
    order.push_back(a);
}

void dfs2(int a){
    if (vis[a]) return;
    vis[a] = true;
    comp.push_back(a);
    for(int b:radj[a]) dfs2(b);
}

int main(){

    int n, m;cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) dfs1(i);
    for(int i = 1;i <= n;i++) vis[i] = false;

    cout << "Components:" << endl;

    reverse(order.begin(), order.end());
    for(int a:order){
        if (vis[a]) continue;

        dfs2(a);
        for(int b:comp) cout << b << " ";
        cout << endl;

        comp.clear();
    }

    /* input
        5 5
        1 2
        2 3
        3 1
        1 4
        1 5
    */

    return 0;
}
