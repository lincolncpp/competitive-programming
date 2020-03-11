#include <bits/stdc++.h>

using namespace std;

// Time complexity O(M*log(M) + N)

int const maxn = 1e5;

vector<int>adj[maxn+7];
int degree[maxn+7] = {};

vector<int>path;
map<pair<int, int>, bool>deleted;

void dfs(int a){
    for(int b:adj[a]){
        if (deleted[{a, b}]) continue;
        deleted[{a, b}] = true;
        deleted[{b, a}] = true;
        dfs(b);
    }

    path.push_back(a);
}

int main(){

    int n, m;cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    // Checking if the given graph has an eulerian path.
    int cnt_odd = 0;
    int start = 1;
    for(int i = 1;i <= n;i++){
        if (degree[i]%2 == 1){
            cnt_odd++;
            start = i;
        }
    }

    if (cnt_odd == 0 || cnt_odd == 2){
        dfs(start);

        cout << "Eulerian path: ";
        for(int a:path) cout << a << " ";
        cout << endl;
    }
    else{
        cout << "The given graph does not have an eulerian path." << endl;
    }

    return 0;
}
