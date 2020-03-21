#include <bits/stdc++.h>

using namespace std;

#define ll long long

// s = text
// t = pattern
vector<int> rabin_karp(const string &s, const string &t){
    const int p = 53;
    const int mod = 1e9+7;
    int n = (int)s.size();
    int m = (int)t.size();

    vector<ll>power(max(n, m));
    ll pwr = 1;
    for(int i = 0;i < max(n, m);i++){
        power[i] = pwr;
        (pwr *= p) %= mod;
    }

    vector<ll>prefix(n+1, 0);
    for(int i = 1;i <= n;i++)
        prefix[i] = (prefix[i-1] + (s[i-1]*power[i-1]) % mod) % mod;

    ll hash_t = 0;
    for(int i = 0;i < m;i++)
        (hash_t += t[i]*power[i] % mod) %= mod;

    vector<int>res;
    for(int i = 0;i+m-1 < n;i++){
        ll a = ((prefix[i+m]-prefix[i]+mod)%mod);
        ll b = (hash_t*power[i]) % mod;

        if (a == b) res.push_back(i);
    }
    return res;
}

int main(){

    vector<int>occurences = rabin_karp("abababab", "ab");
    for(int i:occurences) cout << i << endl;

    return 0;
}
