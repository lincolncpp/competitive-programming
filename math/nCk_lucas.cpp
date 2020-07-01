#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000003;
ll factorial[mod+13] = {};

vector<ll>expand(ll x, ll base){
    vector<ll>res;

    while(x){
        res.push_back(x%base);
        x /= base;
    }

    return res;
}

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll y = modpow(x, n/2);
    if (n&1) return y*y % mod * x % mod;
    return y*y % mod;
}

ll inverse(ll x){
    return modpow(x, mod-2);
}

ll nCk(ll n, ll k){
    vector<ll>nmod = expand(n, mod);
    vector<ll>kmod = expand(k, mod);

    int size = max(nmod.size(), kmod.size());
    nmod.resize(size);
    kmod.resize(size);

    ll res = 1;
    for(int i = 0;i < size;i++){
        if (nmod[i] < kmod[i]) {
            res = 0;
            break;
        }

        res *= factorial[nmod[i]];
        res %= mod;
        res *= inverse(factorial[kmod[i]]);
        res %= mod;
        res *= inverse(factorial[nmod[i]-kmod[i]]);
        res %= mod;
    }

    return res;
}

void build(){
    factorial[0] = 1;
    for(int i = 1;i <= mod;i++) factorial[i] = factorial[i-1]*i % mod;
}

int main(){

    // O(MOD)
    build();

    // O(max(logMOD(N), logMOD(K)) * log2(MOD))
    cout << nCk(1234567895121314313, 92345612131579713) << endl;

    return 0;
}
