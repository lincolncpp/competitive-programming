#include <bits/stdc++.h>

using namespace std;
const int maxn = 4;

// 0 - no solution
// 1 - one solution
// 2 - inf solutions
int gauss(vector<bitset<maxn>> &a){
    int n = a.size();
    int m = maxn-1;

    vector<int>where(m, -1);

    int row = 0;
    for(int col = 0;col < m && row < n;col++){
        for(int i = row;i < n;i++){
            if (a[i][col]){
                swap(a[i], a[row]);
                break;
            }
        }

        // x_col is an independent variable
        if (a[row][col] == 0) continue;

        where[col] = row;
        for(int i = 0;i < n;i++){
            if (i != row && a[i][col]) a[i] ^= a[row];
        }
        row++;
    }

    for(int row = 0;row < n;row++){
        bool value = false;
        for(int col = 0;col < m;col++){
            if (where[col] == -1) continue;
            value ^= a[where[col]][m];
        }
        if (a[row][m] != value) return 0;
    }

    for(int col = 0;col < m;col++){
        if (where[col] == -1) return 2;
    }
    return 1;
}

int main(){

    /*
    SLAE (mod 2)
    1x ^ 1y ^ 1z = 1
    1x ^ 0y ^ 1z = 0
    0x ^ 0y ^ 1z = 1

    Augmented matrix
    1 1 1 1     rev     1 1 1 1
    1 0 1 0    ----->   0 1 0 1
    0 0 1 1             1 1 0 0
    */

    vector<bitset<maxn>>a = {
        bitset<maxn>("1111"),
        bitset<maxn>("0101"),
        bitset<maxn>("1100")
    };
    int sols = gauss(a);

    cout << "solutions: " << sols << endl;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++) cout << a[i][j] << " " ;
        cout << endl;
    }

    // cout << endl;
    // cout << "x = " << ans[0] << endl;
    // cout << "y = " << ans[1] << endl;
    // cout << "z = " << ans[2] << endl;

    return 0;
}
