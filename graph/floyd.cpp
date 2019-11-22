#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
#define N 100

int main(){

    int edge[N][N] = {0};
    edge[0][1] = 10;
    edge[1][2] = 25;
    edge[2][3] = 1;
    edge[0][2] = 200;

    int dist[N][N];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if (i == j) dist[i][j] = 0;
            else if (edge[i][j]) dist[i][j] = edge[i][j];
            else dist[i][j] = INF;
        }
    }

    for(int k = 0;k < N;k++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    cout << dist[0][2] << endl;

    return 0;
}
