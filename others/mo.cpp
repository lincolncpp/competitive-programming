#include <bits/stdc++.h>

using namespace std;

int const maxn = 2e5+7;

struct Query{
    int l, r, id, block;

    bool operator<(const Query &b){
        if (block == b.block){
            if (block%2 == 0) return r < b.r;
            else return r > b.r;
        }
        else return block < b.block;
    }
};

int a[maxn];
Query q[maxn];
int ans = 0;
int ansoff[maxn];

void add(int pos){
    ans += a[pos];
}

void remove(int pos){
    ans -= a[pos];
}

int main(){

    int n, t;cin>>n>>t;
    for(int i = 0;i < n;i++) cin>>a[i];

    int len = (int)sqrt(n)+1;

    for(int i = 0;i < t;i++){
        int l, r;cin>>l>>r;
        l--;r--;

        q[i].l = l;
        q[i].r = r;
        q[i].id = i;
        q[i].block = l/len;
    }
    sort(q, q+t);

    int currentl = 0;
    int currentr = -1;

    for(int i = 0;i < t;i++){
        int l = q[i].l;
        int r = q[i].r;

        while (currentl < l) remove(currentl++);
        while (currentl > l) add(--currentl);
        while (currentr < r) add(++currentr);
        while (currentr > r) remove(currentr--);

        ansoff[q[i].id] = ans;
    }

    for(int i = 0;i < t;i++) cout << ansoff[i] << endl;

    return 0;
}
