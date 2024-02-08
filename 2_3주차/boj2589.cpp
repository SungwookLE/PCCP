#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<char>> world;
vector<vector<int>> lands;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    world = vector<vector<char>>(N, vector<char>(M));

    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            world[i][j] = s[j];
            if (world[i][j] == 'L')
                lands.push_back({i, j});
        }
    }

    int ans = 0;

    for (int i = 0; i < lands.size(); ++i) // 모든 Lands 에서 시작을 다 해보자
    {
        pair<int, int> start = {lands[i][0], lands[i][1]};
        queue<pair<int, int>> candidates;
        vector<vector<int>> searched = vector<vector<int>>(N, vector<int>(M, 0));

        candidates.push(start);
        searched[start.first][start.second] = 1;

        while (!candidates.empty())
        {
            pair<int, int> now = candidates.front();
            candidates.pop();

            for (auto d : delta)
            {

                int next_i = now.first + d[0];
                int next_j = now.second + d[1];

                if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < M)
                {
                    if (searched[next_i][next_j] == 0 && world[next_i][next_j] == 'L')
                    {
                        searched[next_i][next_j] = searched[now.first][now.second] + 1;
                        candidates.push({next_i, next_j});
                    }
                }
            }
        }

        for (auto ss : searched)
        {
            for (auto s : ss)
                ans = max(ans, s - 1);
        }
    }

    cout << ans;

    return 0;
}