#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define hash apdmfoiwahofqjenfoj

const int maxn = 1e5;
const int p = 31;
const int mod = 1e9+7;

ll power[maxn+7] = {};
ll inverse[maxn+7] = {};

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll y = modpow(x, n/2);
    if (n&1) return y*y % mod * x % mod;
    return y*y % mod;
}

struct hash{
    ll val = 0;
    vector<ll>prefix;

    hash(const string &s){
        int n = (int)s.size();
        prefix.resize(n);

        for(int i = 0;i < n;i++){
            (val += s[i]*power[i]) %= mod;
            prefix[i] = val;
        }
    }

    ll substr(int i, int j){
        if (i == 0) return prefix[j];
        return (prefix[j]-prefix[i-1]+mod) % mod *inverse[i] % mod;
    }
};

void build(){
    ll pwr = 1;
    for(int i = 0;i < maxn;i++){
        power[i] = pwr;
        inverse[i] = modpow(power[i], mod-2);
        (pwr *= p) %= mod;
    }
}

int main(){

    build();

    hash h("abacadaabacadaabacadaabacadaabacadaabacadaabacada");
    cout << h.val << endl;
    cout << h.substr(13, 21) << endl;

    return 0;
}
