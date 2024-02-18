#include <bits/stdc++.h>

using namespace std;

int R, C, K;
vector<vector<char>> m;
vector<vector<int>> visited;
map<int, int> ret;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<int> s, int cnt)
{

    if (cnt > K)
        return; // 조기종료

    if (s[0] == 0 && s[1] == C - 1)
    {
        ret[cnt]++;
        return;
    }

    for (auto d : delta)
    {
        int next_i = s[0] + d[0];
        int next_j = s[1] + d[1];

        if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C)
            continue;
        if (visited[next_i][next_j])
            continue;
        if (m[next_i][next_j] == 'T')
            continue;

        visited[next_i][next_j] = 1;
        dfs({next_i, next_j}, cnt + 1);
        visited[next_i][next_j] = 0;
    }
}

int main()
{
    cin >> R >> C >> K;
    m = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<int>>(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cin >> m[i][j];
    }

    // start: {R-1, 0}, goal: {0, C-1}
    vector<int> start = {R - 1, 0};
    visited[start[0]][start[1]] = 1;
    dfs(start, 1);

    cout << ret[K] << endl;

    return 0;
}