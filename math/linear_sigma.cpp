#include <bits/stdc++.h>

using namespace std;

#define N (int)1e6

int sigma[N+1];
int lp[N+1];

void sieve(){
    for(int i = 1;i <= N;i++) {
        sigma[i] = i+1;
        lp[i] = i;
    }
    sigma[1] = 1;

    vector<int>primes;
    for(int i = 2;i <= N;i++){
        if (sigma[i] == i+1) primes.push_back(i);
        for(auto p:primes){
            if (i*p > N) break;
            if (i % p == 0){
                int n = i/lp[i];
                lp[i*p] = lp[i]*p;
                sigma[i*p] = sigma[n]*(lp[i*p]*p-1)/(p-1);
                break;
            }
            else {
                sigma[i*p] = sigma[i]*sigma[p];
                lp[i*p] = p;
            }
        }
    }
}

int main(){

    sieve();

    int x;cin>>x;
    cout << sigma[x] << endl;

    return 0;
}
