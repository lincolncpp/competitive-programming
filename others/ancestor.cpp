#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
vector<int>adj[maxn+7];
int timein[maxn+7] = {};
int timeout[maxn+7] = {};
int curr_time = 0;

void dfs(int a, int parent){
    timein[a] = curr_time++;

    for(int b:adj[a]){
        if (b == parent) continue;
        dfs(b, a);
    }

    timeout[a] = curr_time++;
}

// Check if node a is ancestor of node b
bool is_ancestor(int a, int b){
    if (timein[b] > timein[a] && timeout[b] < timeout[a]) return true;
    return false;
}

int main(){
    // Sample tree
    //
    //         1
    //       /  \
    //      2    3
    //     / \  / \
    //    4  5 6  7
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[3].push_back(7);

    dfs(1, 0);

    for(int i = 1;i <= 7;i++){
        for(int j = i+1;j <= 7;j++){
            if (i == j) continue;

            cout << i << " is ancestor of " << j << ": " << (is_ancestor(i, j)?"YES":"NO") << endl;
        }
    }

    return 0;
}
