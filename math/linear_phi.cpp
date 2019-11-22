#include <bits/stdc++.h>

using namespace std;

#define N (int)1e6

int phi[N+1];

void sieve(){
    for(int i = 1;i <= N;i++) phi[i] = i-1;
    phi[1] = 1;

    vector<int>primes;
    for(int i = 2;i <= N;i++){
        if (phi[i] == i-1) primes.push_back(i);
        for(auto p:primes){
            if (i*p > N) break;
            if (i%p == 0){
                phi[i*p] = phi[i]*p;
                break;
            }
            phi[i*p] = phi[i]*phi[p];
        }
    }
}

int main(){

    sieve();

    int x;cin>>x;
    cout << phi[x] << endl;

    return 0;
}
