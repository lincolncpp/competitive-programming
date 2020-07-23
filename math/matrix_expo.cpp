#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9+7;
const int dim = 2;

struct matrix{
    ll val[dim][dim] = {};

    matrix operator*(const matrix &b){
        matrix c;
        for(int i = 0;i < dim;i++){
            for(int j = 0;j < dim;j++){
                for(int k = 0;k < dim;k++){
                    c.val[i][j] += val[i][k]*b.val[k][j] % mod;
                }
            }
        }
        return c;
    }
};

matrix mpow(matrix a, ll n){
    matrix res;
    for(int i = 0;i < dim;i++) res.val[i][i] = 1;

    while(n > 0){
        if (n&1) res = res*a;
        a = a*a;
        n /= 2;
    }

    return res;
}

int main(){

    matrix a{{
        {1, 0},
        {1, 1}
    }};

    // matrix a^1e18
    a = mpow(a, 10);

    for(int i = 0;i < dim;i++){
        for(int j = 0;j < dim;j++){
            cout << a.val[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
