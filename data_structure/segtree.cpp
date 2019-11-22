#include <bits/stdc++.h>

using namespace std;

template<typename T, int MAXN>
struct segtree{
    vector<T> tree;
    vector<T> lazy;

    segtree(){
        tree.resize(4*MAXN+1);
        lazy.resize(4*MAXN+1);
    }

    void build(const vector<T> &arr, int v = 1, int tl = 0, int tr = MAXN-1){
        if (tr == tl) tree[v] = arr[tl];
        else{
            int mid = (tl+tr)/2;
            build(arr, 2*v, tl, mid);
            build(arr, 2*v+1, mid+1, tr);
            tree[v] = tree[2*v]+tree[2*v+1];
        }
    }

    void push(int v, int tl, int tr){
        tree[v] += (tr-tl+1)*lazy[v];
        if (tr != tl) lazy[2*v] = lazy[2*v+1] = lazy[v];
        lazy[v] = 0;
    }

    T update(int l, int r, T value, int v = 1, int tl = 0, int tr = MAXN-1){
        if (l > r) return 0;
        if (tl == l && tr == r) {
            lazy[v] += value;
            push(v, tl, tr);
            return tree[v];
        }

        push(v, tl, tr);
        int mid = (tl+tr)/2;

        T query = 0;
        query += update(l, min(r, mid), value, 2*v, tl, mid);
        query += update(max(l, mid+1), r, value, 2*v+1, mid+1, tr);
        tree[v] = tree[2*v]+tree[2*v+1];

        return query;
    }

    T query(int l, int r){return update(l, r, 0);}
};

int main(){

    vector<int>v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    segtree<int, 10> tree;
    tree.build(v);

    tree.update(0, 9, 99);
    tree.update(0, 9, 7);
    tree.update(0, 9, -7);
    tree.update(0, 9, -99);

    tree.update(9, 9, 90);

    cout << tree.query(0, 9) << endl;

    return 0;
}
