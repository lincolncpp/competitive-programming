#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool>vis;
string curr;

void dfs(string node, string &A){
    for(int i = 0;i < A.size();i++){
        string edge = node+A[i];
        if (vis[edge]) continue;
        vis[edge] = true;

        dfs(edge.substr(1), A);
        curr += A[i];
    }
}

string bruijn(int n, string A){
    string t(n-1, A[0]);

    vis.clear();
    curr = "";
    dfs(t, A);
    reverse(curr.begin(), curr.end());

    return t+curr;
}

int main(){

    // O(k^n), k = #(A)
    cout << bruijn(3, "ABC") << endl;

    return 0;
}
