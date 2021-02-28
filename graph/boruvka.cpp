#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+123;
int link[maxn];
int siz[maxn];

int find(int x){
    while(link[x] != x){
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    link[b] = a;
    siz[a] += siz[b];
}

int boruvka(int n, const vector<tuple<int, int, int>> &edges){
    for(int i = 1;i <= n;i++){
        link[i] = i;
        siz[i] = 1;
    }

    int total_trees = n;
    int weight = 0;

    while(total_trees > 1){
        vector<int>smallest_edge(n+1, -1);

        for(int i = 0;i < edges.size();i++){
            int a, b, c;
            tie(a, b, c) = edges[i];

            a = find(a);
            b = find(b);
            if (a == b) continue;

            if (smallest_edge[a] != -1 && c < get<2>(edges[smallest_edge[a]])) smallest_edge[a] = i;
            if (smallest_edge[a] == -1) smallest_edge[a] = i;
            if (smallest_edge[b] != -1 && c < get<2>(edges[smallest_edge[b]])) smallest_edge[b] = i;
            if (smallest_edge[b] == -1) smallest_edge[b] = i;
        }

        for(int i = 1;i <= n;i++){
            if (smallest_edge[i] == -1) continue;

            int a, b, c;
            tie(a, b, c) = edges[smallest_edge[i]];

            if (find(a) == find(b)) continue;
            unite(a, b);
            weight += c;
            total_trees--;
        }
    }

    return weight;
}

int main(){

    int n = 4;

    vector<tuple<int, int, int>>edges;
    edges.push_back(make_tuple(1, 2, 100));
    edges.push_back(make_tuple(2, 3, 10));
    edges.push_back(make_tuple(3, 4, 1));
    edges.push_back(make_tuple(4, 1, 10));
    edges.push_back(make_tuple(4, 2, 20));

    cout << boruvka(n, edges) << endl;

    return 0;
}
