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

int dlog(int a, int b, int m){
    int n = (int)sqrt(m)+1;

    int an = 1;
    for(int i = 0;i < n;i++){
        an = (an*(ll)a)%m;
    }

    unordered_map<int, int>values;
    for(int p = 1, cur = an;p <= n;p++){
        if (cur == 0) break;
        if (values.count(cur) == 0) values[cur] = p;
        cur = (cur*(ll)an)%m;
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

    // Find x such that x^k = a (mod n)
    // n must be prime
    int k, a, n;cin>>k>>a>>n;

    // Primitive root of n
    int g = proot(n);

    // Finding one solution with discrete log
    int y = dlog(powmod(g, k, n), a, n);
    if (y == -1) return ((cout << "No solution" << endl), 0);

    // Finding all solutions
    vector<int>solutions;
    int d = (n-1)/__gcd(n-1, k);

    for(int cur = y % d;cur < n-1;cur += d){
        solutions.push_back(powmod(g, cur, n));
    }
    sort(solutions.begin(), solutions.end());

    cout << "List of x such that x^" << k << " = " << a << " (mod "<< n << ")" << endl;
    for(auto s:solutions) cout << s << endl;

    return 0;
}
