#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
vector<int> visited(10, 0);

void postOrder(int node)
{

    for (auto v : adj[node])
    {
        if (visited[v] == 0)
        {
            // 자식의 방문 순서, 즉 왼쪽 오른쪽 순서는 구분하지 않고 구현한 것임
            postOrder(v);
        }
    }
    visited[node] = 1; // 후위방문
    cout << node << "-> ";

}

void inOrder(int node)
{

    if (visited[node] == 0)
    {
        if(adj[node].size()){
            inOrder(adj[node][0]);
            visited[node] = 1; // 중위방문
            cout << node <<"-> ";
            inOrder(adj[node][1]);
        }
        else{
            visited[node] = 1; // 리프 노드 도착
            cout << node <<"-> ";
        }
    }

}


void preOrder(int node)
{
    visited[node] = 1; // 전위방문
    cout << node <<  "-> ";

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
    adj[3].push_back(6);
    adj[3].push_back(7);

    int root = 1;
    
    cout << "1.전위방문(preOrder)\n";
    preOrder(root);
    visited = vector<int>(10, 0);
    cout << endl;

    cout << "2.후위방문(postOrder)\n";
    postOrder(root);
    visited = vector<int>(10, 0);
    cout << endl;

    cout << "3.중위방문(inOrder)\n";
    inOrder(root);
    visited = vector<int>(10, 0);
    cout << endl;
}