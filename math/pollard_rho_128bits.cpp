#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace u128{
    typedef __uint128_t type;

    type mul(type a, type b, type MOD){
        if (a == 0) return 0;
        if (a%2 == 0) return (mul(a/2, b, MOD)*2)%MOD;
        return (mul(a-1, b, MOD)+b)%MOD;
    }

    type pow(type x, type n, type MOD){
        if (n == 0) return 1;
        if (n%2 == 0){
            type y = pow(x, n/2, MOD);
            return mul(y, y, MOD);
        }
        return mul(pow(x, n-1, MOD), x, MOD);
    }

    type abs(type x){
        return (x>0)?x:-x;
    }

    string u128tos(type x){
        if (x == 0) return "0";
        string s;
        while(x){
            s += char('0'+(x%10));
            x /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    type stou128(string s){
        type x = 0;
        type b = 1;
        int i = (int)s.size();
        while(i--){
            x += (s[i]-'0')*b;
            b *= 10;
        }
        return x;
    }
}

u128::type primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool rabin_miller(u128::type x){
    if (x <= 1) return false;
    for(u128::type p:primes) if (x == p) return true;
    for(u128::type p:primes) if (x % p == 0) return false;

    u128::type k = 1;
    while(!(((x-1)>>k)&1)) k++;
    u128::type q = (x-1)>>k;

    for(u128::type p:primes){
        u128::type a = u128::pow(p, q, x);
        if (a == 1 || a == x-1) continue;

        for(u128::type j = 1;j <= k;j++){
            a = u128::mul(a, a, x);
            if (a == x-1) break;
            if (a == 1) return false;
            if (j == k && a != 1) return false;
        }
    }

    return true;
}

u128::type f(u128::type x, u128::type c, u128::type n){
    return (u128::mul(x, x, n)+c)%n;
}

u128::type pollard_rho(u128::type n, u128::type x0, u128::type c){
    u128::type g = 1;
    u128::type x = x0;
    u128::type y = x0;

    while(g == 1){
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        g = __gcd(u128::abs(x-y), n);
    }

    if (g == n) return 0;
    return g;
}

u128::type factor(u128::type x){
    if (x%2 == 0) return 2;
    if (x%3 == 0) return 3;

    int i = 1;
    u128::type f = 0;
    while(f == 0){
        long long x0 = uniform_int_distribution<long long>(0, (1LL<<60))(rng);
        f = pollard_rho(x, x0, i++);
    }

    return f;
}

void factorization(vector<pair<u128::type, int>> &factors, u128::type x){
    if (x == 1) return;
    if (rabin_miller(x)) {
        for(auto &p:factors){
            if (p.first == x) return void(p.second++);
        }
        factors.push_back({x, 1});
    }
    else{
        u128::type f = factor(x);
        factorization(factors, f);
        factorization(factors, x/f);
    }
}

int main(){

    string s;cin>>s;
    u128::type x = u128::stou128(s);

    vector<pair<u128::type, int>>factors;
    factorization(factors, x);

    for(auto f:factors) cout << u128::u128tos(f.first) << "^" << f.second << " ";
    cout << endl;

    return 0;
}
