#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> road;
vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M;

queue<pair<int, int>> candidates;
vector<vector<int>> searched;
pair<int, int> start, goal;

void bfs()
{

    searched[start.first][start.second] = 1;
    candidates.push(start);

    while (candidates.size())
    {

        auto here = candidates.front();
        candidates.pop();

        if (here == goal)
        {
            cout << "도착! " << searched[here.first][here.second] - 1 << endl;
            return;
        }

        for (auto d : delta)
        {

            int next_i = here.first + d.first;
            int next_j = here.second + d.second;

            if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M)
                continue;

            if (road[next_i][next_j] == 1 && searched[next_i][next_j] == 0)
            {
                candidates.push({next_i, next_j});
                searched[next_i][next_j] = searched[here.first][here.second] + 1;
            }
        }
    }

    cout << "실패\n";
    return;
}

int main()
{

    cin >> N >> M;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;

    road.resize(N, vector<int>(M, 0));
    searched.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> road[i][j];
        }
    }

    bfs();

    return 0;
}