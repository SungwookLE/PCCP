#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> visited;

int dfs(int here)
{
    int ret = 1;
    visited[here] = 1; // 컴퓨터 리스트가 트리 형태가 아니라 순환된다면, visited 체크를 해줘야지만 무한 루프가 걸리지 않음.. ㅠ

    for (int neighbor : adj[here])
        if (visited[neighbor] == 0) ret += dfs(neighbor);

    return ret;
}

int main()
{
    cin >> N >> M;
    adj = vector<vector<int>>(N + 1);
    visited = vector<int>(N+1, 0);

    int child, parent;
    for (int i = 0; i < M; ++i)
    {
        cin >> child >> parent;
        adj[parent].push_back(child);
    }

    vector<vector<int>> cnts(N + 1);
    int mx = -1;
    for (int i = 1; i <= N; ++i)
    {   
        visited = vector<int>(N+1, 0);
        int temp = dfs(i);
        cnts[temp].push_back(i);
        mx = max(temp, mx);
    }

    for (auto c : cnts[mx])
        cout << c << " ";

    return 0;
}