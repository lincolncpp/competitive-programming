#include <bits/stdc++.h>

using namespace std;

#define N (1<<10)

int BIT[N+1] = {0};

void add(int i, int x){
    while(i <= N){
        BIT[i] += x;
        i += i&-i;
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += BIT[i];
        i -= i&-i;
    }
    return sum;
}

int main(){

    add(1, 1);
    add(2, 2);
    add(999, 999);

    cout << query(1000) << endl;

    return 0;
}
