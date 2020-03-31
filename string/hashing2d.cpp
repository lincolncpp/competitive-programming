#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9+7;

struct hash2d{
    vector<ll>power[2];
    vector<vector<ll>>h;

    hash2d(const vector<vector<ll>> &matrix, ll p, ll q){
        int n = matrix.size();
        int m = matrix[0].size();

        power[0].assign(n, 0);
        power[1].assign(m, 0);

        power[0][0] = power[1][0] = 1;
        for(int i = 1;i < n;i++) power[0][i] = power[0][i-1]*p % mod;
        for(int i = 1;i < m;i++) power[1][i] = power[1][i-1]*q % mod;

        h.assign(n, vector<ll>(m, 0));
        h[0][0] = matrix[0][0];

        for(int i = 1;i < n;i++) h[i][0] = (h[i-1][0]*p % mod + matrix[i][0]) % mod;
        for(int j = 1;j < m;j++) h[0][j] = (h[0][j-1]*q % mod + matrix[0][j]) % mod;
        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                (h[i][j] += h[i-1][j]*p) %= mod;
                (h[i][j] += h[i][j-1]*q) %= mod;
                (h[i][j] += mod - h[i-1][j-1]*q % mod *p % mod) %= mod;
                (h[i][j] += matrix[i][j]) %= mod;
            }
        }
    }

    ll submatrix(int a, int b, int x, int y){
        ll res = h[x][y];
        if (a-1 >= 0) (res += mod - h[a-1][y]*power[0][x-a+1] % mod) %= mod;
        if (b-1 >= 0) (res += mod - h[x][b-1]*power[1][y-b+1] % mod) %= mod;
        if (a*b > 0) (res += h[a-1][b-1]*power[0][x-a+1] % mod * power[1][y-b+1] % mod) %= mod;
        return res;
    }
};

int main(){

    vector<vector<ll>>v = {
        {1, 2, 0},
        {3, 1, 2},
        {0, 3, 1}
    };

    hash2d hash(v,
        uniform_int_distribution<ll>(100, mod-1)(rng), // base 1
        uniform_int_distribution<ll>(100, mod-1)(rng)  // base 2
    );

    cout << hash.submatrix(1, 1, 2, 2) << endl;
    cout << hash.submatrix(0, 0, 1, 1) << endl;

    return 0;
}
