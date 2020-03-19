#include <bits/stdc++.h>

using namespace std;

int main(){

    string s = "kkabacabaxx";
    int n = (int)s.size();

    int best_len = 0;
    int best_l = 0;
    int best_r = 0;
    for(int i = 0;i < n;i++){

        // even length
        int l = i;
        int r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        int len = r-l-2;
        if (len > best_len){
            best_len = len;
            best_l = l+1;
            best_r = r-1;
        }

        //odd length
        l = i-1;
        r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        len = r-l-2;
        if (len > best_len){
            best_len = len;
            best_l = l+1;
            best_r = r-1;
        }
    }

    cout << s.substr(best_l, best_r-best_l+1) << endl;

    return 0;
}
