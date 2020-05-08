#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;
const int maxn = 1e3;

vector<int>adj[maxn+7];
int parent[maxn+7] = {};
int capacity[maxn+7][maxn+7] = {};
int n;

int bfs(int s, int t){
    fill(parent, parent+n+1, 0);
    parent[s] = -1;

    queue<pair<int, int>>q;
    q.push({s, inf});
    while(!q.empty()){
        int a = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int b:adj[a]){
            if (parent[b] == 0 && capacity[a][b]){
                parent[b] = a;

                int nflow = min(flow, capacity[a][b]);
                if (b == t) return nflow;

                q.push({b, nflow});
            }
        }
    }

    return 0;
}

int max_flow(int s, int t){
    int flow = 0;

    while(int add = bfs(s, t)){
        flow += add;

        int a = t;
        while(parent[a] != s){
            int b = parent[a];
            capacity[a][b] += add;
            capacity[b][a] -= add;
            a = b;
        }
    }

    return flow;
}

void add_edge(int a, int b, int c){
    adj[a].push_back(b);
    adj[b].push_back(a);
    capacity[a][b] = c;
}

int main(){

    // Sample graph
    //
    //       2  -    3 -
    //     /       /     \
    //    1 - 4 - 5 - 6 - 7

    n = 7;
    add_edge(1, 2, 20);
    add_edge(2, 3, 20);
    add_edge(3, 7, 11);
    add_edge(1, 4, 9);
    add_edge(4, 5, 9);
    add_edge(5, 3, 20);
    add_edge(5, 6, 100);
    add_edge(6, 7, 100);

    cout << max_flow(1, 7) << endl;

    return 0;
}
