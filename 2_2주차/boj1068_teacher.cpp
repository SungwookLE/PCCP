#include <bits/stdc++.h>

using namespace std;
int n, r, temp, root;
vector<int> adj[54];

int dfs(int here)
{
    int ret = 0;
    int child = 0;
    for (int there : adj[here])
    {
        if (there == r)
            continue; // 지워졌으니 그 밑으로 내려가지 않음
        ret += dfs(there);
        child++;
    }
    if (child == 0)
        return 1;

    return ret;
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp == -1)
            root = i;
        else
            adj[temp].push_back(i);
    }

    cin >> r;
    if (r==root)
        cout << 0 << "\n";
    else    
        cout << dfs(root) << "\n";

    return 0;
}