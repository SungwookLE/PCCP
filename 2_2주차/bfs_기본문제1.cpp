#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maze;
vector<vector<int>> searched;
vector<vector<int>> deltas = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};
queue<pair<int, int>> candidates;
pair<int, int> start;
pair<int, int> goal;

void bfs(pair<int, int> here)
{

    candidates.push(here);
    searched[here.first][here.second] = 1; // 일부러 1을 해준거임, 0으로 많이 하는데 .., 
    // 양방향 Edge라고 하면 처음 시작한 노드는 별도의 방문처리 로직을 추가해주어야 하니까. 1로 하는 것이 좋다.
    // 나중에 총 이동거리를 구하라고 하면 search[final.first][final.second]-1 로 출력해주면됨

    while (!candidates.empty())
    {

        pair<int, int> now = candidates.front();
        candidates.pop();
        cout << "NOW: " << now.first << " " << now.second << endl;

        if (now == goal)
        {
            cout << "ARRIVED: " << searched[now.first][now.second] - 1<< endl;
            return;
        }
        for (auto d : deltas)
        {
            int next_i = now.first + d[0];
            int next_j = now.second + d[1];

            if (next_i >= 0 && next_j >= 0 && next_i < maze.size() && next_j < maze[0].size())
            {
                if (maze[next_i][next_j] == 1 && searched[next_i][next_j] == 0)
                {
                    searched[next_i][next_j] = searched[now.first][now.second] + 1;
                    candidates.push({next_i, next_j});
                }
            }
        }
    }

    cout << "FAILED" << endl;
    return;
}

int main()
{

    int N, M;
    cin >> N >> M;

    maze = vector<vector<int>>(N, vector<int>(M, 0));
    searched = vector<vector<int>>(N, vector<int>(M, 0));

    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> maze[i][j];

    bfs(start);

    return 0;
}