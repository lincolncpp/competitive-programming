#include <bits/stdc++.h>

using namespace std;

/*
    This structure is 0-based !!!

    Operations O(logN):
    - Insert
    - Erase
    - Update
    - Erase interval
    - Add on the interval
    - Query value
    - Query sum on the interval
    - Reverse on the interval
*/

struct implicit_treap{
    struct node{
        int value, prior;
        node *l = nullptr, *r = nullptr;
        int cnt = 1;
        int sum = 0;
        int lazy = 0;
        bool rev = false;

        node(int k) : value(k), sum(k), prior(rand()) {}
    };

    node *t = nullptr;

    void push(node *n){
        if (n){
            n->value += n->lazy;
            n->sum += cnt(n)*n->lazy;
            if (n->l) n->l->lazy += n->lazy;
            if (n->r) n->r->lazy += n->lazy;
            n->lazy = 0;

            if (n->rev){
                n->rev = false;
                swap(n->l, n->r);
                if (n->l) n->l->rev ^= true;
                if (n->r) n->r->rev ^= true;
            }
        }
    }

    int cnt(node *n){return n?n->cnt:0;}
    void upd_cnt(node *n){if (n) n->cnt = 1+cnt(n->l)+cnt(n->r);}

    int sum(node *n){return n?n->sum:0;}
    void upd_sum(node *n){if (n) n->sum = n->value+sum(n->l)+sum(n->r);}

    void merge(node *&root, node *l, node *r){
        push(l);
        push(r);

        if (!r || !l) root = l?l:r;
        else if (l->prior > r->prior){
            root = l;
            merge(l->r, l->r, r);
        }
        else{
            root = r;
            merge(r->l, l, r->l);
        }

        upd_cnt(root);
        upd_sum(root);
    }

    void split(node *root, int key, node *&l, node *&r, int add = 0){
        if (!root) return void(l = r = nullptr);
        push(root);

        int curr_key = add + cnt(root->l);
        if (key <= curr_key){
            r = root;
            split(root->l, key, l, root->l, add);
        }
        else{
            l = root;
            split(root->r, key, root->r, r, add + 1 + cnt(root->l));
        }

        upd_cnt(root);
        upd_sum(root);
    }

    void insert(int key, int value){
        node *element = new node(value);
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;

        split(t, key, tl, tr);
        merge(aux, tl, element);
        merge(t, aux, tr);
    }

    void erase(node *&root, int key, int add = 0){
        if (!root) return;
        push(root);

        int curr_key = add + cnt(root->l);
        if (curr_key == key) {
            node *aux = root;
            merge(root, root->l, root->r);
            delete aux;
        }
        else{
            if (key < curr_key) erase(root->l, key, add);
            else erase(root->r, key, add + 1 + cnt(root->l));
        }

        upd_cnt(root);
        upd_sum(root);
    }
    void erase(int key){erase(t, key);}

    void erase(int key_l, int key_r){
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;
        split(t, key_l, tl, aux);
        split(aux, key_r-key_l+1, aux, tr);
        merge(t, tl, tr);
    }

    int get(node *root, int key, int add = 0){
        if (!root) return 0;
        push(root);
        int curr_key = add + cnt(root->l);
        if (curr_key == key) return root->value;
        if (key < curr_key) return get(root->l, key, add);
        return get(root->r, key, add + 1 + cnt(root->l));
    }
    int get(int key){return get(t, key);}

    int query(int key_l, int key_r){
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;
        int res = 0;

        split(t, key_l, tl, aux);
        split(aux, key_r-key_l+1, aux, tr);

        push(aux);
        upd_sum(aux);
        res = sum(aux);

        merge(t, tl, aux);
        merge(t, t, tr);

        return res;
    }

    void update(node *&root, int key, int value, int add = 0){
        if (!root) return;
        push(root);

        int curr_key = add + cnt(root->l);
        if (curr_key == key) root->value = value;
        else{
            if (key < curr_key) update(root->l, key, value, add);
            else update(root->r, key, value, add + 1 + cnt(root->l));
        }

        upd_cnt(root);
        upd_sum(root);
    }
    void update(int key, int value){update(t, key, value);}

    void add(int key_l, int key_r, int value){
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;

        split(t, key_l, tl, aux);
        split(aux, key_r-key_l+1, aux, tr);
        aux->lazy += value;
        merge(t, tl, aux);
        merge(t, t, tr);
    }

    void reverse(int key_l, int key_r){
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;

        split(t, key_l, tl, aux);
        split(aux, key_r-key_l+1, aux, tr);
        aux->rev ^= true;
        merge(t, tl, aux);
        merge(t, t, tr);
    }

    void del(node *n){
        if (!n) return;
        del(n->l);
        del(n->r);
        delete n;
    }

    void print(node *n){
        if (!n) return;
        push(n);
        print(n->l);
        cout << n->value << " ";
        print(n->r);
    }

    void print(){
        print(t);
        cout << endl;
    }

    int size(){return cnt(t);}
    ~implicit_treap(){del(t);}
};

implicit_treap t;

int main(){

    t.insert(0, 1);
    t.insert(0, 2);
    t.insert(0, 3);
    t.insert(0, 4);
    t.insert(0, 5);
    t.insert(0, 6);
    t.insert(0, 7);
    t.insert(0, 8);
    t.insert(0, 9);
    t.print();

    t.erase(1);
    t.update(t.size()-1, 1000);
    t.print();

    t.erase(4, 6);
    t.print();

    t.add(-1e9, 1e9, -5);
    t.print();

    cout << "sum(1, 3) = " << t.query(1, 3) << endl;

    t.reverse(-1e9, 1e9);
    t.print();

    cout << "get(0) = " << t.get(0) << endl;

    return 0;
}
