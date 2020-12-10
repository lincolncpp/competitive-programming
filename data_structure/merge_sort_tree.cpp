#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const int maxn = 1e5;
vector<int> tree[4*maxn];
int n;

void build(vector<int>&v, int node = 1, int l = 0, int r = n-1){
    if (l == r) return void(tree[node].push_back(v[l]));
    int mid = (l+r)/2;
    build(v, node*2, l, mid);
    build(v, node*2+1, mid+1, r);
    merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

// Number of elements greater than x
int query(int l, int r, int x, int node = 1, int tl = 0, int tr = n-1){
    if (l > r) return 0;
    if (tl == l && tr == r) return tree[node].end() - lower_bound(all(tree[node]), x+1);
    int mid = (tl+tr)/2;
    int a = query(l, min(mid, r), x, node*2, tl, mid);
    int b = query(max(l, mid+1), r, x, node*2+1, mid+1, tr);
    return a+b;
}

int main(){

    vector<int>v = {9, 9, 5, 1, 6, 3, 4, 8, 0, 6, 1, 5, 2};
    n = v.size();
    build(v);

    cout << query(4, 9, 4) << endl;

    return 0;
}
