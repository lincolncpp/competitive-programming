#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> sieve(int n){
    vector<bool>is_composite(n+1, false);
    vector<ll>primes;

    for(int i = 2;i <= n;i++){
        if (!is_composite[i]) primes.push_back(i);

        for(auto p:primes){
            if (i*p > n) break;
            is_composite[i*p] = true;
            if (i % p == 0) break;
        }
    }

    return primes;
}

vector<bool> ranged_sieve(ll l, ll r){
    vector<ll>primes = sieve((int)sqrt(r)+1);
    vector<bool>mark(r-l+1, true);

    for(auto p:primes){
        ll a = (l/p)*p;
        if (a < l || a == 0) a += p;
        if (a == p) a += p;
        for(;a <= r;a += p) mark[a-l] = false;
    }

    return mark;
}

int main(){

    ll l = 0;
    ll r = 100;

    cout << "Primes between " << l << " and " << r << endl;
    vector<bool>mark = ranged_sieve(l, r);
    for(int i = 0;i < (int)mark.size();i++){
        if (l+i <= 1) continue;
        if (mark[i]) cout << l+i << endl;
    }

    return 0;
}
