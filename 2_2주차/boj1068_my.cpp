#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *parent;
    vector<Node *> child;
};

int dfs(Node *node)
{ 
    int ret = 0;
    for (auto c : node->child)
        if (c != nullptr)
            ret+=dfs(c);

    bool hasChild = false;
    for (auto c : node->child)
        if (c != nullptr)
            hasChild = true;

    if (!hasChild)
        return 1;

    return ret;
}

int main()
{

    int N;
    cin >> N;

    struct Node *Tree = new struct Node[N](); // 초기화를 위해 () 붙여주어야 함. 그래야 0<NULL>으로 초기화가 됨

    int parent;
    int root;
    for (int i = 0; i < N; ++i)
    {
        cin >> parent;
        if (parent != -1)
        {
            Tree[i].parent = &Tree[parent];
            Tree[parent].child.push_back(&Tree[i]);
        }
        else root = i;
    }

    int cut;
    cin >> cut;
    if (cut == root)
    { // 예외 처리
        cout << 0 << endl;
        return 0;
    }

    for (auto &c : Tree[cut].parent->child)
        if (c == &Tree[cut])
            c = nullptr;

    
    cout << dfs(&Tree[root]) << endl;
    return 0;
}
