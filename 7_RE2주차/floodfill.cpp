#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maze;
vector<vector<int>> visited;
vector<int> delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<int> n, int mark)
{

    visited[n[0]][n[1]] = mark;

    for (auto d : delta)
    {
        int next_i = n[0] + d[0];
        int next_j = n[1] + d[1];

        if (next_i < 0 || next_j < 0)
            continue;
        if (next_i >= 6 || next_j >= 6)
            continue;

        if (visited[next_i][next_j] != 0)
            continue;
        if (maze[next_i][next_j] == 0)
            continue;

        dfs({next_i, next_j}, mark);
    }
}

int main()
{

    maze.resize(6, vector<int>(6, 0));
    visited.resize(6, vector<int>(6, 0));

    for (auto &mm : maze)
    {
        for (auto &m : mm)
        {
            cin >> m;
        }
    }

    int mark = 1;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (visited[i][j] == 0 && maze[i][j] == 1)
                dfs({i, j}, mark++);
        }
    }

    for (auto VV : visited)
    {
        for (auto V : VV)
        {
            cout << V << " ";
        }
        cout << endl;
    }

    return 0;
}