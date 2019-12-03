#include <bits/stdc++.h>

using namespace std;

#define ll long long

int powmod(int x, int n, int MOD){
    if (n == 0) return 1;
    if (n%2 == 0){
        ll y = powmod(x, n/2, MOD);
        return (y*y)%MOD;
    }
    return (powmod(x, n-1, MOD)*(ll)x)%MOD;
}

int dlog(int a, int b, int m){
    int n = (int)sqrt(m)+1;

    unordered_map<int, int>values;
    for(int p = 1;p <= n;p++){
        values[powmod(a, n*p, m)] = p;
    }

    int c = b;
    for(int q = 0;q <= n;q++){
        if (values.count(c)){
            int x = values[c]*n-q;
            return x;
        }
        c = (c*(ll)a)%m;
    }

    return -1;
}

int main(){

    cout << dlog(7, 666, 2011) << endl;

    return 0;
}
