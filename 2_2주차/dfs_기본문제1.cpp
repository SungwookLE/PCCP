#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> maze;
vector<vector<int>> visited;
vector<vector<int>> deltas = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

void dfs(int i, int j)
{

    visited[i][j] = 1;

    for (auto d : deltas)
    {
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < maze.size() && next_j < maze[0].size())
        {
            if (maze[next_i][next_j] == 1 && visited[next_i][next_j] == 0)
                dfs(next_i, next_j);
        }
    }
}

int main()
{

    int N, M;
    cin >> N >> M;
    maze = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maze[i][j]; // 1 육지, 0 바다
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == 1 && visited[i][j] == 0)
            {
                dfs(i, j);
                count += 1;
            }
        }
    }

    cout << count << endl;

    return 0;
}