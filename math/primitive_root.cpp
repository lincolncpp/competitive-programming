#include <bits/stdc++.h>

using namespace std;

#define ll long long

int powmod(int x, int n, int MOD){
    if (n == 0) return 1;
    if (n%2 == 0){
        int y = powmod(x, n/2, MOD);
        return (y*(ll)y)%MOD;
    }
    return (powmod(x, n-1, MOD)*(ll)x)%MOD;
}

// p must be prime
int proot(int p){
    int phi = p-1;
    int n = phi;

    vector<int>fact;
    for(int i = 2;i*i <= n;i++){
        if (n%i == 0){
            fact.push_back(i);
            while(n%i == 0) n /= i;
        }
    }
    if (n > 1) fact.push_back(n);

    for(int a = 2;a <= p;a++){
        bool ok = true;
        for(int i = 0;i < fact.size() && ok;i++){
            ok &= powmod(a, phi/fact[i], p) != 1;
        }
        if (ok) return a;
    }

    return -1;
}

int main(){

    // 90441961
    int x;cin>>x;
    cout << proot(x) << endl;

    return 0;
}
