#include <bits/stdc++.h>

using namespace std;

vector<int> adj[6];
vector<int> visited(6, 0);

void dfs(int node)
{
    cout << node << endl;
    visited[node] = 1;

    for (auto neighbor : adj[node])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor);
        }
    }

    cout << node << "종료되었음" << endl;
}

int main()
{

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    dfs(1);

    return 0;
}



// 아래는 참고, visited 를 체크하고 호출하는게 아니라 호출한다음에 체크하는 식으로도 구현할 수 있다.
    // 일명 못먹어도 고

void dfs2(int node){

    if(visited[node]) return;
    visited[node] = 1;

    for(int there: adj[node] )
        dfs2(there);
}