#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 3
#define MOD 1000000007

struct matrix{
    ll arr[N][N] = {0};

    matrix operator*(const matrix &b){
        matrix c;

        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                for(int k = 0;k < N;k++){
                    c.arr[i][j] += arr[i][k]*b.arr[k][j];
                    c.arr[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

matrix mexp(matrix a, ll n){
    if (n == 1) return a;
    else if (n%2==0){
        matrix b = mexp(a, n/2);
        return b*b;
    }
    else return mexp(a, n-1)*a;
}

int main(){

    matrix a;
    a.arr[0][0] = 1;
    a.arr[1][0] = 1;
    a.arr[2][2] = 1;
    a.arr[2][0] = 1;
    a.arr[2][1] = 1;

    a = mexp(a, 400); // matrix a^400

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cout << a.arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
