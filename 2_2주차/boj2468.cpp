#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> land;
vector<vector<int>> visited;
vector<vector<int>> deltas = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

void dfs(int i, int j, int h)
{
    visited[i][j] = 1;

    for (auto d : deltas)
    {
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < N)
        {
            if (visited[next_i][next_j] == 0 && land[next_i][next_j] > h)
                dfs(next_i, next_j, h);
        }
    }
}

int main()
{

    cin >> N;
    land = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> land[i][j];
        }
    }

    int answer = 0;
    for (int h = 0; h <= 100; ++h) // 에라이 문제 오타
    {
        visited = vector<vector<int>>(N, vector<int>(N, 0));
        int count = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                if (land[i][j] > h && visited[i][j] == 0)
                {
                    count++;
                    dfs(i, j, h);
                }
            }
        
        if (answer < count)
            answer = count;
    }

    cout << answer << "\n";

    return 0;
}