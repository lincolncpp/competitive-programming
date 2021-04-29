#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(n)
*/

const int maxn = 1e7;

int dcnt[maxn+123];
pair<int, int> lp[maxn+123];

void sieve(){
    for(int i = 1;i <= maxn;i++) {
        dcnt[i] = 2;
        lp[i] = {i, 1};
    }
    dcnt[1] = 1;

    vector<int>primes;
    for(int i = 2;i <= maxn;i++){
        if (dcnt[i] == 2) primes.push_back(i);
        for(auto p:primes){
            if (i*p > maxn) break;
            if (i%p == 0) {
                lp[i*p] = lp[i];
                lp[i*p].first *= p;
                lp[i*p].second++;
                dcnt[i*p] = dcnt[i/lp[i].first]*(lp[i*p].second+1);
            }
            else {
                dcnt[i*p] = dcnt[i]*dcnt[p];
                lp[i*p] = {p, 1};
            }
        }
    }
}

int main(){

    sieve();

    cout << dcnt[21613] << endl;

    return 0;
}
