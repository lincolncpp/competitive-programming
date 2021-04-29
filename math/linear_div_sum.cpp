#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(n)
*/

#define ll long long
const int maxn = 1e7;

ll dsum[maxn+123];
ll lp[maxn+123];

void sieve(){
    for(int i = 1;i <= maxn;i++) {
        dsum[i] = i+1;
        lp[i] = i;
    }
    dsum[1] = 1;

    vector<ll>primes;
    for(int i = 2;i <= maxn;i++){
        if (dsum[i] == i+1) primes.push_back(i);
        for(ll p:primes){
            if (i*p > maxn) break;
            if (i % p == 0){
                ll n = i/lp[i];
                lp[i*p] = lp[i]*p;

                // use long long to avoid overflow here
                dsum[i*p] = dsum[n]*(lp[i*p]*p-1)/(p-1);
                break;
            }
            else {
                dsum[i*p] = dsum[i]*dsum[p];
                lp[i*p] = p;
            }
        }
    }
}

int main(){

    sieve();

    cout <<  dsum[21613] << endl;

    return 0;
}
