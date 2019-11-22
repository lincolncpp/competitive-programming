#include <bits/stdc++.h>

using namespace std;

int ext_gcd(int a, int b, int &x, int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = ext_gcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

int main(){

    int a = 2011;
    int b = 4201;

    int i, j;
    ext_gcd(a, b, i, j);

    cout << "("<<i<<")*" << a << " + ("<<j<<")*" << b << " = " << __gcd(a, b) << endl;

    return 0;
}
