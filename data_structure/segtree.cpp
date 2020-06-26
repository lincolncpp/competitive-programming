#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int tree[4*maxn+11] = {};
int n;

void update(int i, int val, int node = 1, int tl = 0, int tr = n-1){
    if (tl > i || tr < i) return;
    if (tl == tr && tl == i) return void(tree[node] = val);

    int mid = (tl+tr)/2;
    update(i, val, node*2, tl, mid);
    update(i, val, node*2+1, mid+1, tr);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

// Range min query
int query(int l, int r, int node = 1, int tl = 0, int tr = n-1){
    if (l > r) return 0x7fffffff;
    if (tl == l && tr == r) return tree[node];

    int mid = (tl+tr)/2;
    int left = query(l, min(r, mid), node*2, tl, mid);
    int right = query(max(l, mid+1), r, node*2+1, mid+1, tr);
    return min(left, right);
}

int main(){

    vector<int>v = {-555, 70, 4201, -956, 30};
    n = v.size();

    for(int i = 0;i < n;i++) update(i, v[i]);
    cout << query(0, n-1) << endl;

    return 0;
}
