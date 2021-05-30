#include <bits/stdc++.h>

using namespace std;

/*
    With map<char, int> next
        Build: O(nlogk)
        Memory: O(n)

    With int next[k]
        Build: O(n)
        Memory: O(nk)
*/

const int maxn = 1e5+123;

struct state{
    int link, len;
    map<char, int>next;
};

state st[2*maxn];
int aut_sz, last;

void init(){
    aut_sz = 1;
    last = 0;
    st[0].link = -1;
    st[0].len = 0;
}

void append(char c){
    int curr = aut_sz++;
    st[curr].len = st[last].len+1;

    int p = last;
    while(p != -1 && !st[p].next.count(c)){
        st[p].next[c] = curr;
        p = st[p].link;
    }
    if (p == -1) {
        st[curr].link = 0;
    }
    else{
        int q = st[p].next[c];
        if (st[q].len == st[p].len+1){
            st[curr].link = q;
        }
        else{
            int clone = aut_sz++;
            st[clone].len = st[p].len+1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = clone;
            st[curr].link = clone;
        }
    }
    last = curr;
}

void build(const string &s){
    init();
    for(int i = 0;i < s.size();i++) append(s[i]);
}

int main(){

    build("abb");

    for(int i = 0;i < aut_sz;i++){
        for(auto &pr:st[i].next) cout << i << " --" << pr.first << "--> " << pr.second << endl;
    }

    return 0;
}
