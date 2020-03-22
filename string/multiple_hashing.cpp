#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define hash apdmfoiwahofqjenfoj

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6;
const ll mod = 1e9+7;
const int hashes = 3;

ll power[maxn+7][hashes] = {};
ll inverse[maxn+7][hashes] = {};

const ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll y = modpow(x, n/2);
    if (n&1) return y*y % mod * x % mod;
    return y*y % mod;
}

struct hash{
    int n;
    vector<vector<ll>>prefix, suffix;

    hash(const string &s){
        n = (int)s.size();

        prefix.resize(n);
        suffix.resize(n);
        for(int i = 0;i < n;i++){
            prefix[i].resize(hashes);
            suffix[i].resize(hashes);
        }

        for(int j = 0;j < hashes;j++) {
            prefix[0][j] = s[0];
            suffix[n-1][j] = s[n-1];
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j < hashes;j++){
                (prefix[i][j] = prefix[i-1][j] + s[i]*power[i][j] % mod) %= mod;
            }
        }
        for(int i = n-2;i >= 0;i--){
            for(int j = 0;j < hashes;j++){
                (suffix[i][j] = suffix[i+1][j] + s[i]*power[n-1-i][j] % mod) %= mod;
            }
        }
    }

    ll substr(int i, int j, int k){
        if (i == 0) return prefix[j][k];
        return ((prefix[j][k]-prefix[i-1][k]+mod) % mod)*inverse[i][k] % mod;
    }

    ll rsubstr(int i, int j, int k){
        if (j == n-1) return suffix[i][k];
        return ((suffix[i][k]-suffix[j+1][k]+mod) % mod)*inverse[n-1-j][k] % mod;
    }

    bool is_palindrome(int i, int j){
        if (i == j) return true;
        int len = j-i+1;

        for(int k = 0;k < hashes;k++){
            if (substr(i, i+len/2-1, k) != rsubstr(j-len/2+1, j, k)) return false;
        }
        return true;
    }
};

void build(){
    ll p[hashes] = {};
    ll ip[hashes] = {};

    for(int i = 0;i < hashes;i++){
        p[i] = uniform_int_distribution<int>(100, mod-1)(rng);
        ip[i] = modpow(p[i], mod-2);

        power[0][i] = 1;
        inverse[0][i] = 1;
    }

    for(int i = 1;i < maxn;i++){
        for(int j = 0;j < hashes;j++){
            (power[i][j] = power[i-1][j]*p[j] % mod) %= mod;
            (inverse[i][j] = inverse[i-1][j]*ip[j] % mod) %= mod;
        }
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
