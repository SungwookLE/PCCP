#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<int> delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<vector<int>> candidates;
vector<vector<int>> searched;

int main()
{
    cin >> N >> M;
    maze.resize(N, vector<int>(M, 0));
    searched.resize(N, vector<int>(M, 0));

    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            maze[i][j] = s[j] - '0';
        }
    }

    candidates.push({0, 0});
    searched[0][0] = 1;

    while (candidates.size())
    {
        auto here = candidates.front();
        candidates.pop();

        if (here[0] == N - 1 && here[1] == M - 1)
        {
            cout << searched[here[0]][here[1]];
            return 0;
        }

        for (auto d : delta)
        {
            int next_i = here[0] + d[0];
            int next_j = here[1] + d[1];

            if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M)
                continue;
            if (maze[next_i][next_j] == 1 && searched[next_i][next_j] == 0)
            {
                candidates.push({next_i, next_j});
                searched[next_i][next_j] = searched[here[0]][here[1]] + 1;
            }
        }
    }

    cout << "FAIL\n";
    return 0;
}