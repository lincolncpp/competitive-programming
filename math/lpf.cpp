#include <bits/stdc++.h>

using namespace std;

#define N 5000000

int lpf[N+1] = {};

void sieve(){
    for(int i = 1;i <= N;i++) lpf[i] = i;
    for(int i = 2;i <= N;i++){
        if (lpf[i] == i){
            for(int j = 2;i*j <= N;j++){
                int x = i*j;
                if (lpf[x] == x) lpf[x] = i;
            }
        }
    }
}

vector<int> factorization(int x){
    vector<int>primes;
    while(x != 1){
        primes.push_back(lpf[x]);
        x /= lpf[x];
    }
    return primes;
}

int main(){

    sieve();
    int x;cin>>x;

    cout << "Factors of " << x << endl;
    for(auto p:factorization(x)) cout << p << endl;

    return 0;
}
