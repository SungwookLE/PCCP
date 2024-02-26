#include <bits/stdc++.h>

using namespace std;

int T;
int N, M; // N: nodes, M: edges
vector<vector<int>> graph;
vector<int> visited;

int check(int node){
    visited[node] = 1;

    int ret = 1;

    for(int v : graph[node]){
        if(visited[v] == 0)
            ret+=check(v);
    }

    return ret;    
}


int main(){

    cin >> T;

    for(int t = 0 ; t < T ; ++t){
        cin >> N >> M;
        graph = vector<vector<int>>(N+1);
        visited = vector<int>(N+1,0);
        
        int a, b;
        bool isExist = false;
        for(int i=0 ; i < M ; ++i){
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (M == N-1){ // Edge = Vertex-1; 이어야지만 트리이고, 이보다 Edge가 많다면 순환이 있다는 의미로 트리가 아니다. ㅠㅠ
            if ( N == check(a)) cout << "tree\n";
            else cout << "graph\n";
        }
        else cout << "graph\n";

    }

    return 0;
}