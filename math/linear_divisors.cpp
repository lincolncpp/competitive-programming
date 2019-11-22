#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)1e6

int divisors[MAXN+1];
pair<int, int> lp[MAXN+1];

void sieve(){
    for(int i = 1;i <= MAXN;i++) {
        divisors[i] = 2;
        lp[i] = {i, 1};
    }
    divisors[1] = 1;
    vector<int>primes;
    for(int i = 2;i <= MAXN;i++){
        if (divisors[i] == 2) primes.push_back(i);
        for(auto p:primes){
            if (i*p > MAXN) break;
            if (i%p == 0) {
                lp[i*p] = lp[i];
                lp[i*p].first *= p;
                lp[i*p].second++;
                divisors[i*p] = divisors[i/lp[i].first]*(lp[i*p].second+1);
            }
            else {
                divisors[i*p] = divisors[i]*divisors[p];
                lp[i*p] = {p, 1};
            }
        }
    }
}

int main(){

    sieve();

    int x;cin>>x;
    cout << divisors[x] << endl;

    return 0;
}
