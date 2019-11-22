#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mul(ll a, ll b, ll MOD){
    if (a == 0) return 0;
    if (a%2 == 0) return (mul(a/2, b, MOD)*2)%MOD;
    return (mul(a-1, b, MOD)+b)%MOD;
}

ll pow(ll x, ll n, ll MOD){
    if (n == 0) return 1;
    if (n%2 == 0){
        ll y = pow(x, n/2, MOD);
        return mul(y, y, MOD);
    }
    return mul(pow(x, n-1, MOD), x, MOD);
}

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

bool rabin_miller(ll x){
    if (x <= 1) return false;
    for(ll p:primes) if (x == p) return true;
    for(ll p:primes) if (x % p == 0) return false;

    ll k = 1;
    while(!(((x-1)>>k)&1)) k++;
    ll q = (x-1)>>k;

    for(ll p:primes){
        ll a = pow(p, q, x);
        if (a == 1 || a == x-1) continue;

        for(ll j = 1;j <= k;j++){
            a = mul(a, a, x);
            if (a == x-1) break;
            if (a == 1) return false;
            if (j == k && a != 1) return false;
        }
    }

    return true;
}

ll f(ll x, ll c, ll n){
    return (mul(x, x, n)+c)%n;
}

ll pollard_rho(ll n, ll x0, ll c){
    ll g = 1;
    ll x = x0;
    ll y = x0;

    while(g == 1){
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        g = __gcd(abs(x-y), n);
    }

    if (g == n) return 0;
    return g;
}


ll factor(ll x){
    if (x%2 == 0) return 2;
    if (x%3 == 0) return 3;

    int i = 1;
    ll f = 0;
    while(f == 0){
        ll x0 = uniform_int_distribution<ll>(0, (1LL<<60))(rng);
        f = pollard_rho(x, x0, i++);
    }

    return f;
}

void factorization(vector<pair<ll, int>> &factors, ll x){
    if (x == 1) return;
    if (rabin_miller(x)) {
        for(auto &p:factors){
            if (p.first == x) return void(p.second++);
        }
        factors.push_back({x, 1});
    }
    else{
        ll f = factor(x);
        factorization(factors, f);
        factorization(factors, x/f);
    }
}

int main(){

    ll x;cin>>x;

    vector<pair<ll, int>>factors;
    factorization(factors, x);

    for(auto f:factors) cout << f.first << "^" << f.second << " ";
    cout << endl;

    return 0;
}
