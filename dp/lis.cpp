#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;

int main(){

    vector<int>vec = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = (int)vec.size();

    int dp[maxn] = {};

    for(int i = 0;i < n;i++){
        dp[i] = 1;
        for(int j = 0;j < i;j++){
            if (vec[i] > vec[j]) dp[i] = max(dp[i], 1+dp[j]);
        }
    }

    for(int i = 0;i < n;i++) cout << dp[i] << " ";

    return 0;
}
