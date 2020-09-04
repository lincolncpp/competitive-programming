#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<tuple<int, int, int>>edges;

// max can find positive cycle
// min can find negative cycle
void bellmanford(vector<int>&d){
    for(int i = 1;i <= n-1;i++){
        for(auto &e:edges){
            int a, b, w;
            tie(a, b, w) = e;
            d[b] = max(d[b], d[a]+w);
        }
    }
}

int main(){

    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a, b, w;cin>>a>>b>>w;
        edges.push_back({a, b, w});
    }

    vector<int>d1(n+11, -1e9);
    d1[1] = 0;
    bellmanford(d1);

    vector<int>d2 = d1;
    bellmanford(d2);

    bool cycle = false;
    for(int i = 1;i <= n;i++){
        if (d2[i] > d1[i]) cycle = true;
    }

    if (cycle) cout << "Positive cycle found" << endl;
    else cout << "No positive cycle found" << endl;

    /* input
        3 3
        1 2 1
        2 3 1
        3 1 100
    */

    return 0;
}
