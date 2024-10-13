#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> land, visited;
vector<int> delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mx = 0, ans = 0;

void dfs(vector<int> here, int h)
{

    visited[here[0]][here[1]] = 1;

    for (auto d : delta)
    {
        int next_i = here[0] + d[0];
        int next_j = here[1] + d[1];

        if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= N)
            continue;
        if (visited[next_i][next_j] == 0 && land[next_i][next_j] - h > 0)
        {
            dfs({next_i, next_j}, h);
        }
    }
}

int main()
{
    cin >> N;
    land.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> land[i][j];

            if (mx < land[i][j])
                mx = land[i][j];
        }
    }

    mx = max(100, mx);

    for (int h = 0; h <= mx; ++h)
    {

        visited = vector<vector<int>>(N, vector<int>(N, 0));

        int comp = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == 0 
                    && land[i][j] - h > 0)
                {
                    comp++;
                    dfs({i, j}, h);
                }
            }
        }

        if (ans < comp)
            ans = comp;
    }
    cout << ans << endl;

    return 0;
}