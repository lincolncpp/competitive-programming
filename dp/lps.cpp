#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;

int main(){

    string s = "iabacaxi";
    int n = (int)s.size();

    int dp[maxn][maxn] = {};
    for(int i = 0;i < n;i++) dp[i][i] = 1;

    for(int i = n-1;i >= 0;i--){
        for(int j = i+1;j < n;j++){
            if (s[i] == s[j]) dp[i][j] = 2+dp[i+1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }

    int l = 0;
    int r = n-1;
    cout << "Length of the largest palindrome from " << l << " to " << r << endl;
    cout << dp[l][r] << endl;

    return 0;
}
