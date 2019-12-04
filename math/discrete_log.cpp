#include <bits/stdc++.h>

using namespace std;

#define ll long long

int dlog(int a, int b, int m){
    int n = (int)sqrt(m)+1;

    int an = 1;
    for(int i = 0;i < n;i++){
        an = (an*(ll)a)%m;
    }

    unordered_map<int, int>values;
    for(int p = 1, cur = an;p <= n;p++){
        if (cur == 0) break;
        if (values.count(cur) == 0) values[cur] = p;
        cur = (cur*(ll)an)%m;
    }

    int c = b;
    for(int q = 0;q <= n;q++){
        if (values.count(c)){
            int x = values[c]*n-q;
            return x;
        }
        c = (c*(ll)a)%m;
    }

    return -1;
}

int main(){

    cout << dlog(3, 4, 11) << endl;

    return 0;
}
