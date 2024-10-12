#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int v)
{

    visited[v] = 1;
    for (auto node : adj[v])
    {
        if (visited[node] == 0)
            dfs(node);
    }
    // 종료는 호출 스택의 최상단 부터 (그래프의 leaf 부분부터!)
    cout << v << "terminated!" << endl;

    return;
}

void dfs2(int v)
{
    if (visited[v]==1) return;
    
    visited[v] = 1;
    for (auto node : adj[v])
    {
        dfs(node);
    }
    cout << v << "terminated!" << endl;

    return;
}

int main()
{

    adj.resize(5);
    visited.resize(5);

    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(2);

    dfs(0);

    return 0;
}