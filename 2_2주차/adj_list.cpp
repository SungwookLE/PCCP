#include <bits/stdc++.h>

using namespace std;
#define VE 10

vector<int> adj[VE];
bool visited[VE];

void dfs(int i){
    
    visited[i] = 1;

    for(int neighbor: adj[i]){
        if (visited[neighbor] == 0){
            cout << i << "->" << neighbor << endl;
            dfs(neighbor);
        }
    }
}


int main(){

    // Q1.
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    // Q2. DFS
    dfs(1);

    return 0;
}