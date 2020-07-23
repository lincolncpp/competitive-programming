#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9+7;

struct matrix{
    vector<vector<ll>> val;

    matrix(int n){
        val.resize(n);
        fill(val.begin(), val.end(), vector<ll>(n));
    }

    matrix operator*(const matrix &b){
        int n = (int)b.val.size();

        matrix c(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    c.val[i][j] += b.val[i][k]*val[k][j];
                    c.val[i][j] %= mod;
                }
            }
        }
        return c;
    }
};

matrix mpow(matrix a, ll n){
    if (n == 1) return a;
    matrix b = mpow(a, n/2);
    if (n&1) return b*b*a;
    return b*b;
}

int main(){

    matrix a(3);
    a.val = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // matrix a^1e18
    a = mpow(a, 1000000000000000000);

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout << a.val[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
