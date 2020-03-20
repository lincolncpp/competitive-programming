#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define hash apdmfoiwahofqjenfoj

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6;
const ll mod = 1e9+7;
ll p = 0;

ll power[maxn+7] = {};
ll inverse[maxn+7] = {};

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll y = modpow(x, n/2);
    if (n&1) return y*y % mod * x % mod;
    return y*y % mod;
}

struct hash{
    int n;
    ll val = 0;
    ll rval = 0;
    vector<ll>prefix;
    vector<ll>suffix;

    hash(const string &s){
        n = (int)s.size();
        prefix.resize(n);
        suffix.resize(n);

        for(int i = 0;i < n;i++){
            (val += s[i]*power[i]) %= mod;
            prefix[i] = val;
        }

        for(int i = n-1;i >= 0;i--){
            (rval += s[i]*power[n-1-i]) %= mod;
            suffix[i] = rval;
        }
    }

    ll substr(int i, int j){
        if (i == 0) return prefix[j];
        return (prefix[j]-prefix[i-1]+mod) % mod *inverse[i] % mod;
    }

    ll rsubstr(int i, int j){
        if (j == n-1) return suffix[i];
        return (suffix[i]-suffix[j+1]+mod) % mod *inverse[n-1-j] % mod;
    }

    bool is_palindrome(int i, int j){
        if (i == j) return true;
        int len = j-i+1;
        int k = len/2;
        return substr(i, i+k-1) == rsubstr(j-k+1, j);
    }
};

void build(){
    while(p < 100) p = rng();
    ll ip = modpow(p, mod-2);

    power[0] = 1;
    inverse[0] = 1;
    for(int i = 1;i < maxn;i++){
        power[i] = power[i-1]*p % mod;
        inverse[i] = inverse[i-1]*ip % mod;
    }
}

int main(){

    build();

    string s = "abacaba";
    int n = (int)s.size();

    hash h(s);
    cout << h.is_palindrome(0, n-1) << endl;

    return 0;
}
