#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)1e6

int divisors[MAXN+1];
int lp[MAXN+1];

void sieve(){
    for(int i = 1;i <= MAXN;i++) {
        divisors[i] = i+1;
        lp[i] = i;
    }
    divisors[1] = 1;

    vector<int>primes;
    for(int i = 2;i <= MAXN;i++){
        if (divisors[i] == i+1) primes.push_back(i);
        for(auto p:primes){
            if (i*p > MAXN) break;
            if (i % p == 0){
                int n = i/lp[i];
                lp[i*p] = lp[i]*p;
                divisors[i*p] = divisors[n]*(lp[i*p]*p-1)/(p-1);
                break;
            }
            else {
                divisors[i*p] = divisors[i]*divisors[p];
                lp[i*p] = p;
            }
        }
    }
}

int main(){

    sieve();

    int x;cin>>x;

    // Sum of divisors
    cout << divisors[x] << endl;

    return 0;
}
