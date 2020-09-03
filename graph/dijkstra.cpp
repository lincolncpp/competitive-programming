#include <bits/stdc++.h>

using namespace std;

const int inf = 1<<29;
const int maxn = 1e5+13;

vector<pair<int, int>>adj[maxn+11];
int dist[maxn+11] = {};
bool vis[maxn+13] = {};

int main(){

    int n = 10;
    adj[1].push_back(make_pair(7, 20));
    adj[1].push_back(make_pair(2, 5));
    adj[1].push_back(make_pair(3, 1));
    adj[3].push_back(make_pair(2, 10));
    adj[3].push_back(make_pair(10, 1));
    adj[10].push_back(make_pair(7, 16));

    for(int i = 1;i <= n;i++) dist[i] = inf;
    dist[1] = 0;

    priority_queue<pair<int, int>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();

        if (vis[a]) continue;
        vis[a] = true;

        for(auto &pr:adj[a]){
            int b = pr.first;
            int w = pr.second;
            if (dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }

    for(int i = 1;i <= n;i++){
        cout << "dist from " << 1 << " to " << i << ": " << dist[i] << endl;
    }

    return 0;
}
