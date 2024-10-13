#include <bits/stdc++.h>

using namespace std;

int T;
int M, N, K;

vector<vector<int>> land, visited;
vector<vector<int>> bachu;
vector<int> delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<int> here)
{
    visited[here[0]][here[1]] = 1;
    for (auto d : delta)
    {
        int next_i = here[0] + d[0];
        int next_j = here[1] + d[1];
        if (next_i < 0 || next_j < 0 || next_i >= M || next_j >= N)
            continue;
        if (visited[next_i][next_j] == 0 && land[next_i][next_j] == 1)
        {
            dfs({next_i, next_j});
        }
    }
    return;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        cin >> M >> N >> K;
        land = vector<vector<int>>(M, vector<int>(N, 0));
        visited = vector<vector<int>>(M, vector<int>(N, 0));
        bachu.clear();

        int row, col;
        for (int j = 0; j < K; ++j)
        {
            cin >> row >> col;
            land[row][col] = 1;
            bachu.push_back({row, col});
        }

        int ans = 0;
        for (auto b : bachu)
        {
            if (visited[b[0]][b[1]] == 0)
            {
                ans++;
                dfs(b);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}