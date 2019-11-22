#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
#define N 1000

int main(){

    vector<pair<int, int>>adj[N];
    adj[0].push_back(make_pair(7, 20));
    adj[0].push_back(make_pair(2, 5));
    adj[0].push_back(make_pair(3, 1));
    adj[3].push_back(make_pair(2, 10));
    adj[3].push_back(make_pair(10, 1));
    adj[10].push_back(make_pair(7, 16));

    int dist[N];
    for(int i = 0;i < N;i++) dist[i] = INF;
    dist[0] = 0;

    bool processed[N] = {false};

    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for(auto bb:adj[a]){
            int b = bb.first;
            int w = bb.second;
            if (dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }

    cout << dist[7] << endl;

    return 0;
}
