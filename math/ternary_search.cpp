#include <bits/stdc++.h>

using namespace std;

int f(int x){
    return (x-5)*(x-5);
}

// Discrete algorithm
int ternary_search(int l, int r){
    while(r-l >= 3){
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;

        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }

    int res = 0x7fffffff;
    for(;l <= r;l++) res = min(res, f(l));
    return res;
}

double g(double x){
    return x*exp(x);
}

// Real algorithm
double ternary_search(double l, double r){
    const double eps = 1e-9;

    while(r-l > eps){
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;

        if (g(m1) > g(m2)) l = m1;
        else r = m2;
    }

    return g(l);
}

int main(){

    cout << "Discrete function f(x) = (x-5)^2" << endl;
    cout << "Minimum: " << ternary_search(-20, 20) << endl << endl;

    cout << "Real function g(x) = x*e^x" << endl;
    cout << "Minimum: " << ternary_search(-1e3, 1e3) << endl;

    return 0;
}
