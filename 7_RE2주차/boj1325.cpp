#include <bits/stdc++.h>
using namespace std;

int N, M;
typedef struct graph_st{
    int here; // 사이클 구조가 있을수도 있기 때문에 추가해준것
    vector<graph_st*> child;
}graph;

vector<vector<int>> result;
vector<int> visited;

int dfs(graph* node){
    int ret = 1;
    visited[node->here] = 1;

    for(auto c : node->child){
        if (visited[c->here] == 0)
            ret+=dfs(c);
    }
    return ret;
}

int main(){

    cin >> N >> M;
    graph *Node = new graph[N+1]();

    int a, b;
    for(int i =0 ; i < M ; ++i){
        cin >> a >> b;
        Node[a].here = a;
        Node[b].here = b;
        Node[b].child.push_back(&Node[a]);
    }
    
    for(int i =0 ; i <= N ; ++i){
        visited = vector<int>(N+1,0);
        int ret = dfs(&Node[i]);
        result.push_back({ret, i});
    }

    sort(result.begin(), result.end(), [](auto a, auto b){
        if (a[0] > b[0]) return true;
        else if (a[0] == b[0]) return a[1] < b[1];
        else return false;
    });

    int cmp = result[0][0];
    for(int i =0 ; i < result.size(); ++i){
        if (cmp == result[i][0])
            cout << result[i][1] << " ";
        else break;
    }

    return 0;
}