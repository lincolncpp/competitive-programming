#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ll mul(ll a, ll b, ll MOD){
    if (a == 0) return 0;
    if (a%2 == 0) return (mul(a/2, b, MOD)*2)%MOD;
    else return (mul(a-1, b, MOD)+b)%MOD;
}

ll fast_exp(ll x, ll n, ll m){
    if (n == 0) return 1;
    if (n%2 == 0){
        ll y = fast_exp(x, n/2, m);
        return mul(y, y, m);
    }
    return mul(fast_exp(x, n-1, m), x, m);
}

bool rabin_miller(ll x){
    if (x <= 1) return false;
    for(ll p:primes) if (x == p) return true;
    for(ll p:primes) if (x % p == 0) return false;

    ll k = __builtin_ctzll(x-1);
    ll q = (x-1)>>k;

    for(ll p:primes){
        ll a = fast_exp(p, q, x);
        if (a == 1 || a == x-1) continue;

        for(int j = 1;j <= k;j++){
            a = mul(a, a, x);
            if (a == x-1) break;
            if (a == 1) return false;
            if (j == k && a != 1) return false;
        }
    }

    return true;
}

int main(){

    cout << rabin_miller(1000000007) << endl;

    return 0;
}
