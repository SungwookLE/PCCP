#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> farm, visited;
vector<vector<int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int M, N, K;

void dfs(int i, int j, int id)
{

    visited[i][j] = 1; // 방문 처리

    for (auto d : deltas)
    {
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < M && next_j < N)
        {

            if (visited[next_i][next_j] == 0 && farm[next_i][next_j] == 1)
            {

                dfs(next_i, next_j, id);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    vector<int> answer;
    for (int i = 0; i < T; ++i)
    {
        cin >> M >> N >> K;
        farm = vector<vector<int>>(M, vector<int>(N, 0));
        visited = vector<vector<int>>(M, vector<int>(N, 0));

        int a, b;
        for (int kk = 0; kk < K; ++kk)
        {
            cin >> a >> b;
            farm[a][b] = 1;
        }

        int id = 0;
        for (int si = 0; si < M; ++si)
        {
            for (int sj = 0; sj < N; ++sj)
            {
                if (visited[si][sj] == 0 && farm[si][sj] == 1)
                {
                    id++;
                    dfs(si, sj, id);
                }
            }
        }
        answer.push_back(id);
    }

    for (auto a : answer)
        cout << a << endl;

    return 0;
}