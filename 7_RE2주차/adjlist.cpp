#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10]; // 2차원
vector<int> visited(10);

void dfs(int V){
    cout << V << endl;
    visited[V] = 1;
    for(int there : adj[V]){
        if(visited[there] == 0)
            dfs(there);
    }
    return;
}


int main(){

    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[3].push_back(9);

    for(int i =0 ; i < 10; ++i){
        if(visited[i]==0) dfs(i);
    }

    return 0;
}