#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define hash apdmfoiwahofqjenfoj

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6;
const ll mod = 1e9+7;

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
    vector<ll>prefix, suffix;

    hash(const string &s){
        n = (int)s.size();

        prefix.resize(n);
        suffix.resize(n);

        prefix[0] = s[0];
        suffix[n-1] = s[n-1];

        for(int i = 1;i < n;i++){
            (prefix[i] = prefix[i-1] + s[i]*power[i] % mod) %= mod;
        }
        for(int i = n-2;i >= 0;i--){
            (suffix[i] = suffix[i+1] + s[i]*power[n-1-i] % mod) %= mod;
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
    ll p = uniform_int_distribution<int>(100, mod-1)(rng);
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
