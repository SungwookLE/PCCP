#include <bits/stdc++.h>

using namespace std;

vector<int> adj[6];
int visited[6];

void postOrder(int node){
    if (visited[node] == 1) return;

    for(int there: adj[node]){
        postOrder(there);
    }
    visited[node] = 1;
    cout << node << " ";
    return;
}

void preOrder(int node){
    if (visited[node] == 1) return;

    visited[node] =1 ;
    cout << node << " ";
    for(int there: adj[node]){
        preOrder(there);
    }

    return;
}

void inOrder(int node){
    if (visited[node] == 1) return;

    int left, right;
    switch (adj[node].size())
    {
    case 1:
        left = adj[node][0];
        inOrder(left);
        visited[node] = 1;
        cout << node << " ";
        break;
    case 2:
        left = adj[node][0], right = adj[node][1];
        inOrder(left);
        visited[left] = 1;
        cout << node << " ";
        inOrder(right);
        break;
    default:
        visited[node] = 1;
        cout << node << " ";
        break;
    }
    
    return;
}   


int main(){

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    // 후위순회
    cout <<"후위순회:";
    postOrder(root);
    cout << endl;

    memset(visited, 0, sizeof(visited));
    cout <<"전위순회:";
    preOrder(root);
    cout << endl;

    memset(visited, 0, sizeof(visited));
    cout <<"중위순회:";
    inOrder(root);
    cout << endl;

    return 0;
}