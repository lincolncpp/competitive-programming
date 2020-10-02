#include <bits/stdc++.h>

using namespace std;

int n;

struct node{
    node *l, *r;
    int sum;

    node(int x){
        l = nullptr;
        r = nullptr;
        sum = x;
    }
    node(node* left, node* right){
        l = left;
        r = right;
        if (l != nullptr) sum += l->sum;
        if (r != nullptr) sum += r->sum;
    }
};

node* build(const vector<int> &v, int tl = 0, int tr = n-1){
    if (tl == tr) return new node(v[tl]);
    int mid = (tl+tr)/2;
    return new node(build(v, tl, mid), build(v, mid+1, tr));
}

int query(node *seg, int l, int r, int tl = 0, int tr = n-1){
    if (l > r) return 0;
    if (tl == l && tr == r) return seg->sum;
    int mid = (tl+tr)/2;
    return  query(seg->l, l, min(r, mid), tl, mid)+
            query(seg->r, max(l, mid+1), r, mid+1, tr);
}

node *update(node *seg, int i, int x, int tl = 0, int tr = n-1){
    if (tl == tr) return new node(x);
    int mid = (tl+tr)/2;
    if (i <= mid) return new node(update(seg->l, i, x, tl, mid), seg->r);
    else return new node(seg->l, update(seg->r, i, x, mid+1, tr));
}

int main(){

    vector<int>v = {10, 0, 0, 10};
    n = v.size();
    node *seg = build(v);

    node *seg2 = update(seg, 1, 10);
    node *seg3 = update(seg2, 2, 10);
    cout << query(seg, 0, n-1) << endl;
    cout << query(seg2, 0, n-1) << endl;
    cout << query(seg3, 0, n-1) << endl;

    return 0;
}
