#include <bits/stdc++.h>

using namespace std;

/*
    Runtime: O(nm)
    n - vertices
    m - edges
*/

const int maxn = 1e3;

int vis[maxn+123];
int mt[maxn+123];
vector<int> g[maxn+123];

bool kuhn(int v, int t){
    if (vis[v] == t) return false;
    vis[v] = t;

    for(int u:g[v]){
        if (mt[u] == -1 || kuhn(mt[u], t)){
            mt[u] = v;
            return true;
        }
    }
    return false;
}


int main(){

    for(int i = 0;i < maxn;i++) {
        mt[i] = -1;
        vis[i] = -1;
    }

    g[1].push_back(4);
    g[1].push_back(5);
    g[1].push_back(6);
    g[2].push_back(5);
    g[2].push_back(6);
    g[3].push_back(5);

    for(int i = 1;i <= 3;i++) kuhn(i, i); // first part vertex
    for(int i = 4;i <= 6;i++){ // second part vertex
        if (mt[i] != -1){
            cout << mt[i] << " matches " << i << endl;
        }
    }

    return 0;
}
