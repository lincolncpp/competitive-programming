#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll mod = 1e9+7;

vector<vector<ll>> multiply(const vector<vector<ll>>&a, const vector<vector<ll>>&b){
    vector<vector<ll>>res((int)a.size(), vector<ll>((int)a.size()));
    for(int i = 0;i < (int)a.size();i++){
        for(int j = 0;j < (int)a.size();j++){
            for(int k = 0;k < (int)a.size();k++){
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>>a, ll n){
    vector<vector<ll>>res((int)a.size(), vector<ll>((int)a.size()));
    for(int i = 0;i < (int)a.size();i++) res[i][i] = 1;

    while(n > 0){
        if (n&1) res = multiply(res, a);
        a = multiply(a, a);
        n /= 2;
    }

    return res;
}

int main(){

    vector<vector<ll>>r = {
        {10, 1},
        {1, 5}
    };
    r = power(r, 2);

    for(int i = 0;i < (int)r.size();i++){
        for(int j = 0;j < (int)r.size();j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
