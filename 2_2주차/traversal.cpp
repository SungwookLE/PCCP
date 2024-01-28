#include <bits/stdc++.h>

using namespace std;

vector<int> adj[6];
vector<int> visited(6, 0);

void postOrder(int node)
{

    for (auto v : adj[node])
    {
        if (visited[v] == 0)
        {
            // 자식의 방문 순서, 즉 왼쪽 오른쪽 순서는 구분하지 않고 구현한 것임
            postOrder(v);
            visited[node] = 1; // 후위방문
        }
    }

    cout << node << "방문" << endl;
}

void preOrder(int node)
{
    visited[node] = 1; // 전위방문
    cout << node << "방문" << endl;

    for (auto v : adj[node])
    {
        if (visited[v] == 0)
        {
            // 자식의 방문 순서, 즉 왼쪽 오른쪽 순서는 구분하지 않고 구현한 것임
            preOrder(v);
        }
    }
}

int main()
{

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    preOrder(root);
}