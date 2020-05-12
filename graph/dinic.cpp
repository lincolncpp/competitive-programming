#include <bits/stdc++.h>

using namespace std;

const int inf = 1<<29;
const int maxn = 1e3;

struct flow_edge{
    int to, cap, flow;
    flow_edge(int b, int c) : to(b), cap(c), flow(0){}
};
vector<flow_edge>edge;
vector<vector<int>>adj(maxn+7);
vector<int>level(maxn+7);
vector<int>ptr(maxn+7);

void add_edge(int a, int b, int c){
    int n = (int)edge.size();
    edge.emplace_back(b, c);
    edge.emplace_back(a, 0);
    adj[a].push_back(n);
    adj[b].push_back(n+1);
}

bool bfs(int s, int t){
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(int e:adj[a]){
            if (edge[e].cap-edge[e].flow == 0) continue;
            if (level[edge[e].to] != -1) continue;

            level[edge[e].to] = level[a]+1;
            q.push(edge[e].to);
        }
    }

    return level[t] != -1;
}

int dfs(int a, int t, int pushed){
    if (pushed == 0) return 0;
    if (a == t) return pushed;

    for(int &i = ptr[a];i < (int)adj[a].size();i++){
        int e = adj[a][i];
        if (level[edge[e].to] != level[a]+1) continue;
        if (edge[e].cap-edge[e].flow == 0) continue;

        int f = dfs(edge[e].to, t, min(edge[e].cap-edge[e].flow, pushed));
        if (f == 0) continue;

        edge[e].flow += f;
        edge[e^1].flow -= f;
        return f;
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;

    while(true){
        fill(level.begin(), level.end(), -1);
        level[s] = 0;

        if (!bfs(s, t)) break;

        fill(ptr.begin(), ptr.end(), 0);
        while(int add = dfs(s, t, inf)){
            flow += add;
        }
    }

    return flow;
}

int main(){

    // Sample graph
    //
    //       2  -    3 -
    //     /       /     \
    //    1 - 4 - 5 - 6 - 7

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
