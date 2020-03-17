#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int n, m;
int status[maxn] = {};
vector<int>adj[maxn];
vector<int>vec;
bool has_cycle = false;

void dfs(int a){
    if (status[a] == 1) return void(has_cycle = true);
    status[a] = 1;

    for(int b:adj[a]){
        if (status[b] == 2) continue;
        dfs(b);
    }

    vec.push_back(a);
    status[a] = 2;
}

void topological_sort(){
    for(int i = 1;i <= n;i++){
        if (status[i] == 2) continue;
        dfs(i);
    }
    reverse(vec.begin(), vec.end());
}

int main(){

    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
    }

    topological_sort();

    if (has_cycle) cout << "the given graph has cycle." << endl;
    else for(int e:vec) cout << e << " ";

    return 0;
}
