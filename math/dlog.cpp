#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll mul(ll a, ll b, ll MOD){
    return (__int128(a)*b)%MOD;
}

ll dlog(ll a, ll b, ll m){
    ll n = sqrt(m)+1;

    ll an = 1;
    for(int i = 0;i < n;i++){
        an = mul(an, a, m);
    }

    unordered_map<ll, ll>values;
    for(ll p = 1, cur = an;p <= n;p++){
        if (cur == 0) break;
        if (values.count(cur) == 0) values[cur] = p;
        cur = mul(cur, an, m);
    }

    ll c = b;
    for(ll q = 0;q <= n;q++){
        if (values.count(c)){
            ll x = values[c]*n-q;
            return x;
        }
        c = mul(c, a, m);
    }

    return -1;
}

int main(){

    cout << dlog(5, 33, 58) << endl;

    return 0;
}
