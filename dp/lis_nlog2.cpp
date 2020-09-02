#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int>v(1e5);
    generate(v.begin(), v.end(), rand);

    vector<int>dp;
    for(int x:v){
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << endl;

    return 0;
}
