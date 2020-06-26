#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int tree[4*maxn+7] = {};
int lazy[4*maxn+7] = {};
int n;

void build(const vector<int>&v, int node = 1, int tl = 0, int tr = n-1){
    if (tl == tr) return void(tree[node] = v[tl]);
    int mid = (tl+tr)/2;
    build(v, node*2, tl, mid);
    build(v, node*2+1, mid+1, tr);
    tree[node] = tree[node*2]+tree[node*2+1];
}

void push(int node, int tl, int tr){
    if (tl == tr) tree[node] += lazy[node];
    else{
        tree[node] += lazy[node]*(tr-tl+1);
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

int update(int l, int r, int val, int node = 1, int tl = 0, int tr = n-1){
    push(node, tl, tr);
    if (l > r) return 0;
    if (tl == l && tr == r){
        lazy[node] += val;
        push(node, tl, tr);
        return tree[node];
    }
    int mid = (tl+tr)/2;
    int left = update(l, min(r, mid), val, node*2, tl, mid);
    int right = update(max(mid+1, l), r, val, node*2+1, mid+1, tr);
    tree[node] = tree[node*2]+tree[node*2+1];
    return left+right;
}

int query(int l, int r){
    return update(l, r, 0);
}

int main(){

    vector<int>v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = v.size();

    build(v);

    update(0, n-1, 10);
    cout << query(0, n-1) << endl;

    return 0;
}
