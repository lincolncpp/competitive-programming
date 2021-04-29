#include <bits/stdc++.h>

using namespace std;

/*
    Build: O(nlogn)
    Factor: O(logn)
*/

const int maxn = 1e6;

int lpf[maxn+123] = {};

void build(){
    for(int i = 1;i <= maxn;i++) lpf[i] = i;
    for(int i = 2;i <= maxn;i++){
        if (lpf[i] == i){
            for(int j = 2;i*j <= maxn;j++){
                int x = i*j;
                if (lpf[x] == x) lpf[x] = i;
            }
        }
    }
}

vector<int> factor(int x){
    vector<int>primes;
    while(x != 1){
        primes.push_back(lpf[x]);
        x /= lpf[x];
    }
    return primes;
}

int main(){

    build();

    int x = 123456;
    cout << "Factors of " << x << ": " << endl;
    for(auto p:factor(x)) cout << p << " ";
    cout << endl;

    return 0;
}
