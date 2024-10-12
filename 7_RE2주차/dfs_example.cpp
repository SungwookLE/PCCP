#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> sea;
vector<vector<int>> visited;
vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(vector<int> now)
{
    cout << now[0] <<"," << now[1] << endl;
    visited[now[0]][now[1]] = 1;

    for (auto d : delta)
    {
        int next_i = now[0] + d.first;
        int next_j = now[1] + d.second;

        if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M)
            continue;
        if (sea[next_i][next_j] == 1 && visited[next_i][next_j] == 0)
        {
            dfs({next_i, next_j});
        }
    }

    return;
}
int main()
{
    cin >> N >> M;
    sea.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> sea[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (sea[i][j] == 1 && visited[i][j] == 0)
            {
                ans++;
                cout << ans <<"시작\n";
                dfs({i, j});
            }
        }
    }

    cout << ans;

    return 0;
}