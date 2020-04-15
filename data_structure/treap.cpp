#include <bits/stdc++.h>

using namespace std;

struct treap{
private:
    struct node{
        int key, prior;
        node *l = nullptr, *r = nullptr;
        int cnt = 1;

        node(int k) : key(k), prior(rand()) {}
    };

    node *t = nullptr;

    int cnt(node *n){
        return n?n->cnt:0;
    }

    void upd_cnt(node *n){
        if (n) n->cnt = 1+cnt(n->l)+cnt(n->r);
    }

    void split(node *root, int key, node *&l, node *&r){
        if (!root) l = r = nullptr;
        else if (key <= root->key){
            r = root;
            split(root->l, key, l, root->l);
        }
        else{
            l = root;
            split(root->r, key, root->r, r);
        }

        upd_cnt(l);
        upd_cnt(r);
    }

    void insert(node *&root, node *element){
        if (!root) return void(root = element);

        if (element->prior > root->prior){
            split(root, element->key, element->l, element->r);
            root = element;
        }
        else{
            if (element->key < root->key) insert(root->l, element);
            else insert(root->r, element);
        }

        upd_cnt(root);
    }

    void merge(node *&root, node *l, node *r){
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
    }

    void erase(node *&root, int key){
        if (!root) return;
        if (root->key == key) {
            node *aux = root;
            merge(root, root->l, root->r);
            delete aux;
        }
        else{
            if (key < root->key) erase(root->l, key);
            else erase(root->r, key);
        }

        upd_cnt(root);
    }

    void del(node *n){
        if (!n) return;
        del(n->l);
        del(n->r);
        delete n;
    }

    /* ==================== EXTRA ==================== */
    int kth(node *root, int pos){ // O(log(N))
        if (!root) return 0;

        int p = 1+cnt(root->l);
        if (p == pos) return root->key;

        if (p > pos) return kth(root->l, pos);
        else return kth(root->r, pos-p);
    }

    node *unite(node *l, node *r){ // O(M*log(N/M))
        if (!l || !r) return l?l:r;
        if (l->prior < r->prior) swap(l, r);
        node *tl;
        node *tr;
        split(r, l->key, tl, tr);
        l->l = unite(l->l, tl);
        l->r = unite(l->r, tr);

        upd_cnt(l);
        return l;
    }

    void print(node *n){
        if (!n) return;
        print(n->l);
        cout << n->key << " ";
        print(n->r);
    }

public:
    void insert(int key){
        insert(t, new node(key));
    }

    void erase(int key){
        erase(t, key);
    }

    ~treap(){
        del(t);
    }

    /* ==================== EXTRA ==================== */
    bool find(int key){
        node *aux = t;
        while(aux && aux->key != key){
            if (key < aux->key) aux = aux->l;
            else aux = aux->r;
        }
        return aux != nullptr;
    }

    int order_of_key(int key){
        int res = 0;

        node *l = nullptr, *r = nullptr;
        split(t, key, l, r);
        res = cnt(l);

        merge(t, l, r);
        return res;
    }

    void erase_range(int l, int r){
        node *tl = nullptr, *tr = nullptr, *aux = nullptr;
        split(t, l, tl, aux);
        split(aux, r+1, aux, tr);
        del(aux);
        merge(t, tl, tr);
    }

    int kth(int pos){
        return kth(t, pos+1);
    }

    void unite(treap &b){
        t = unite(t, b.t);
        b.t = nullptr;
    }

    int size(){
        return cnt(t);
    }

    void print(){
        print(t);
        cout << endl;
    }
};

int main(){

    treap k;
    k.insert(-5);
    k.insert(20);

    treap t;
    t.insert(11);
    t.insert(200);
    t.insert(156);
    t.insert(7);
    t.insert(10);
    t.insert(12);

    cout << "Treap t" << endl;
    t.print();
    cout << endl;

    cout << "Treap k" << endl;
    k.print();
    cout << endl;

    cout << "Treap t + k" << endl;
    t.unite(k);
    t.print();
    cout << endl;

    cout << "Erase [10, 100]" << endl;
    t.erase_range(10, 100);
    t.print();
    cout << endl;

    cout << "3-th element" << endl;
    cout << t.kth(3) << endl;
    cout << endl;

    cout << "order of key 156" << endl;
    cout << t.order_of_key(156) << endl;
    cout << endl;

    cout << "find 11" << endl;
    cout << t.find(11) << endl;

    return 0;
}
