#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+123;

struct operation{
    int a, b;
    int rnka, rnkb;
    operation(int a, int b, int rnka, int rnkb) : a(a), b(b), rnka(rnka), rnkb(rnkb) {}
};

int link[maxn];
int rnk[maxn];
int comp = 0;
stack<operation>history;

int find(int x){
    while(x != link[x]) x = link[x];
    return x;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rnk[b] > rnk[a]) swap(a, b);
    history.push(operation(a, b, rnk[a], rnk[b]));
    comp--;
    link[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

void rollback(){
    if (history.empty()) return;

    operation op = history.top();
    history.pop();

    link[op.a] = op.a;
    rnk[op.a] = op.rnka;
    link[op.b] = op.b;
    rnk[op.b] = op.rnkb;
    comp++;
}

int main(){

    int n = 10;
    comp = n;
	for(int i = 1;i <= n;i++) link[i] = i;
    
    unite(1, 2);
    cout << comp << endl;
    unite(3, 4);
    cout << comp << endl;
    unite(1, 3);
    cout << comp << endl;
    
    rollback();
    rollback();
    rollback();
    
    cout << comp << endl;

    return 0;
}
