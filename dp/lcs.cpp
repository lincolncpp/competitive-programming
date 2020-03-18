#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;

int main(){

    string s1 = "abacaba";
    string s2 = "abacate";
    int n = (int)s1.size();
    int m = (int)s2.size();

    int dp[maxn][maxn] = {};
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
