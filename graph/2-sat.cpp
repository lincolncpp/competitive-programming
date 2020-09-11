#include <bits/stdc++.h>

using namespace std;

const int maxn = 3 * 2;

vector<int>adj[maxn+11];
vector<int>radj[maxn+11];
int vis[maxn+11] = {};
int comp[maxn+11] = {};
vector<int>order;

void dfs1(int a){
    if (vis[a]) return;
    vis[a] = true;
    for(int b:adj[a]) dfs1(b);
    order.push_back(a);
}

void dfs2(int a, int component){
    if (vis[a]) return;
    vis[a] = true;
    comp[a] = component;
    for(int b:radj[a]) dfs2(b, component);
}

int neg(int a){
    if (a&1) return a+1;
    else return a-1;
}

int main(){

    // sample expression
    // (1^2)v(-3^-1)

    // (1^-2)
    // not 1 implies 2
    adj[neg(1*2)].push_back(2*2);
    radj[2*2].push_back(neg(1*2));
    // not 2 implies 1
    adj[neg(2*2)].push_back(1*2);
    radj[1*2].push_back(neg(2*2));

    // (-3^-1)
    // 3 implies not 1
    adj[3*2].push_back(neg(1*2));
    radj[neg(1*2)].push_back(3*2);
    // 1 implies not 3
    adj[1*2].push_back(neg(3*2));
    radj[neg(3*2)].push_back(1*2);

    for(int i = 1;i <= maxn;i++) dfs1(i);
    for(int i = 1;i <= maxn;i++) vis[i] = false;

    reverse(order.begin(), order.end());
    int curr = 1;
    for(int a:order){
        if (vis[a]) continue;
        dfs2(a, curr);
        curr++;
    }

    bool solution = true;
    bool ans[maxn+11] = {};
    for(int i = 1;i <= maxn/2;i++){
        int a = i*2;
        int a_ = i*2-1;

        if (comp[a] == comp[a_]) solution = false;
        ans[i] = comp[a] > comp[a_];
    }

    if (!solution) cout << "There is no solution" << endl;
    else{
        for(int i = 1;i <= maxn/2;i++){
            if (ans[i]) cout << i << ": true" << endl;
            else cout << i << ": false" << endl;
        }
    }

    return 0;
}
