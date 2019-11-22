#include <bits/stdc++.h>

using namespace std;

#define N (int)1e5

int link[N];
int siz[N];

int find(int x){
    while(x != link[x]) x = link[x];
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b]) swap(a, b);
    link[b] = a;
    siz[a] += siz[b];
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){

    for(int i = 0;i < N;i++){
        link[i] = i;
        siz[i] = 1;
    }

    vector<tuple<int, int, int>>edges;
    edges.push_back(make_tuple(1, 2, 100));
    edges.push_back(make_tuple(2, 3, 10));
    edges.push_back(make_tuple(3, 4, 1));
    edges.push_back(make_tuple(4, 1, 10));
    edges.push_back(make_tuple(4, 2, 20));

    sort(edges.begin(), edges.end(), [](tuple<int, int, int>a, tuple<int, int, int>b){
        return get<2>(a) < get<2>(b);
    });

    int weight = 0;
    for(auto e:edges){
        int a = get<0>(e);
        int b = get<1>(e);
        int w = get<2>(e);
        if (!same(a, b)){
            weight += w;
            unite(a, b);
        }
    }

    cout << weight << endl;

    return 0;
}
