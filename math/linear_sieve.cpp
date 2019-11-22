#include <bits/stdc++.h>

using namespace std;

#define MAXN (int)1e6

vector<int>primes;
bool is_composite[MAXN+1] = {};

void sieve(){
    for(int i = 2;i <= MAXN;i++){
        if (!is_composite[i]) primes.push_back(i);
        for(auto p:primes){
            if (p*i > MAXN) break;
            is_composite[p*i] = true;
            if (i % p == 0) break;
        }
    }
}

int main(){

    sieve();

    return 0;
}
