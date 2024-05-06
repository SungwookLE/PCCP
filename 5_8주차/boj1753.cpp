#include <bits/stdc++.h>

using namespace std;


int V, E;
int K;
int u, v, w;

vector<pair<int, int>> adj[20001];
int dist[20001];
const int INF = 987654321;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    cin >> V>> E;
    cin >> K;

    fill(dist, dist+20001, INF);

    for(int i =0 ; i < E ; ++i){
        cin>> u >> v >> w;
        adj[u].push_back({w,v});
    }

    pq.push({0,K});
    dist[K] = 0;

    while(pq.size()){
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        // 다르다는 의미는,
        // 최소값 정점에 대한 pq가 아니라는 의미임, 
        // 불필요한 정점이므로, 그 밑에 대해서는 계속 탐색할 필요가 없음
        if (dist[here] != here_dist) continue;

        for(auto there: adj[here]){

            int _dist = there.first;
            int _there = there.second;

            if (dist[_there] > dist[here]+_dist){
                dist[_there] = dist[here]+_dist;
                pq.push({dist[_there], _there});
            }
        }
    }

    for(int i = 1; i <= V; ++i){

        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] <<"\n";
    }


    return 0;
}