#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-9;

// 0 - no solution
// 1 - one solution
// 2 - inf solutions
int gauss(vector<vector<double>> &a, vector<double> &ans){
    int n = a.size();
    int m = a[0].size()-1;

    vector<int>where(m, -1);

    int row = 0;
    for(int col = 0;col < m && row < n;col++){
        int sel = row;
        for(int i = row;i < n;i++){
            if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
        }

        // x_col is an independent variable
        if (abs(a[sel][col]) < eps) continue;

        where[col] = row;
        for(int j = col;j <= m;j++) swap(a[sel][j], a[row][j]);
        for(int i = 0;i < n;i++){
            if (i == row) continue;
            double c = a[i][col] / a[row][col];
            for(int j = col;j <= m;j++){
                a[i][j] -= a[row][j] * c;
            }
        }

        row++;
    }

    ans.assign(m, 0);
    for(int col = 0;col < m;col++){
        if (where[col] == -1) continue;
        ans[col] = a[where[col]][m] / a[where[col]][col];
    }

    for(int row = 0;row < n;row++){
        double sum = 0;
        for(int col = 0;col < m;col++){
            if (where[col] == -1) continue;
            sum += a[row][col] * ans[col];
        }
        if (abs(sum - a[row][m]) > eps) return 0;
    }

    for(int col = 0;col < m;col++){
        if (where[col] == -1) return 2;
    }
    return 1;
}

int main(){

    /*
    SLAE
    1x + 1y + 1z = 3
    1x - 2y + 1z = 0
    2x + 2y - 1z = 5

    Augmented matrix
    1  1  1  3
    1 -2  1  0
    2  2 -1  5
    */

    vector<vector<double>>a = {
        {1, 1, 1, 3},
        {1, -2, 1, 0},
        {2, 2, -1, 5}
    };
    vector<double>ans;
    gauss(a, ans);

    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++) cout << a[i][j] << " " ;
        cout << endl;
    }

    cout << endl;
    cout << "x = " << ans[0] << endl;
    cout << "y = " << ans[1] << endl;
    cout << "z = " << ans[2] << endl;

    return 0;
}
