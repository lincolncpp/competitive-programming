#include <bits/stdc++.h>

using namespace std;

struct node{
    node *child[30] = {};
    bool is_end = false;

    void add(const string &s){
        node *curr = this;

        for(int i = 0;i < (int)s.size();i++){
            int x = s[i]-'a';

            if (curr->child[x] == nullptr) curr->child[x] = new node();
            curr = curr->child[x];
        }
        curr->is_end = true;
    }

    void remove(const string &s){
        node *curr = this;

        for(int i = 0;i < (int)s.size();i++){
            int x = s[i]-'a';

            if (curr->child[x] == nullptr) return;
            curr = curr->child[x];
        }
        curr->is_end = false;
    }

    bool query(const string &s){
        node *curr = this;

        for(int i = 0;i < (int)s.size();i++){
            int x = s[i]-'a';

            if (curr->child[x] == nullptr) return false;
            curr = curr->child[x];
        }
        return curr->is_end;
    }
};

node *trie = new node();

int main(){

    trie->add("aba");
    trie->add("abacaba");
    cout << trie->query("aba") << endl;
    cout << trie->query("abacaba") << endl;

    trie->remove("aba");
    cout << trie->query("aba") << endl;
    cout << trie->query("abacaba") << endl;

    return 0;
}
