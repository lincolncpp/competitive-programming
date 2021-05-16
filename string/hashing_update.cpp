#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(nlogn)
    Substring hash: O(logn)
    Check palindrome: O(logn)
    Update: O(logn)
*/

#define ll long long
#define hash apdmfoiwahofqjenfoj

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}

const ll mod = 1e9+7;
const int maxn = 2e5+123;

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll y = modpow(x, n/2);
    if (n&1) return y*y % mod * x % mod;
    return y*y % mod;
}

// 0-based
struct fenwick{
    ll bit[maxn+123];

    void update(int i, int x){
        for(i++;i < maxn;i += i&-i) (bit[i] += x) %= mod;
    }

    ll query(int i){
        ll res = 0;
        for(i++;i > 0;i -= i&-i) (res += bit[i]) %= mod;
        return res;
    }
};

struct hash{
    int n;
    string s;
    fenwick pref, suff;
    vector<ll>power, inverse;

    hash(const string &t, ll p){
        s = t;
        n = (int)s.size();

        power.assign(n, 0);
        inverse.assign(n, 0);

        p %= mod;
        ll ip = modpow(p, mod-2); // inverse of p
        power[0] = inverse[0] = 1;
        for(int i = 1;i < n;i++) power[i] = power[i-1]*p % mod;
        for(int i = 1;i < n;i++) inverse[i] = inverse[i-1]*ip % mod;
        for(int i = 0;i < n;i++) pref.update(i, s[i]*power[i] % mod);
        for(int i = 0;i < n;i++) suff.update(i, s[n-1-i]*power[i] % mod);
    }

    ll substr(int i, int j){
        if (i == 0) return pref.query(j);
        return (pref.query(j)-pref.query(i-1)+mod) % mod *inverse[i] % mod;
    }

    ll rsubstr(int i, int j){
        if (j == n-1) return suff.query(n-1-i);
        return (suff.query(n-1-i)-suff.query(n-1-(j+1))+mod) % mod *inverse[n-1-j] % mod;
    }

    bool is_palindrome(int i, int j){
        if (i == j) return true;
        int len = j-i+1;
        int k = len/2;
        return substr(i, i+k-1) == rsubstr(j-k+1, j);
    }

    void update(int i, char c){
        pref.update(i, -(s[i]*power[i] % mod)+mod);
        suff.update(n-1-i, -(s[i]*power[n-1-i] % mod)+mod);
        s[i] = c;
        pref.update(i, s[i]*power[i] % mod);
        suff.update(n-1-i, s[i]*power[n-1-i] % mod);
    }
};

int main(){

    string s = "zbaoabk";
    int n = (int)s.size();

    hash h(s, rnd(100, mod-2));

    h.update(0, 'x');
    h.update(3, 'a');
    h.update(n-1, 'x');
    cout << h.s << endl;

    cout << h.substr(0, n-1) << endl;
    cout << h.rsubstr(0, n-1) << endl;
    cout << h.is_palindrome(0, n-1) << endl;

    return 0;
}
