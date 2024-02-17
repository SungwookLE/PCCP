#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<int> visited;
vector<vector<int>> delta = {{-1, 0},{0, 1}, {1, 0}, {0, -1} };
int mx = 0;

void dfs(vector<int> here,  int ans)
{   
    mx = max(ans, mx);

    for (int i = 0 ; i < 4; ++i)
    {
        int next_i = here[0] + delta[i][0];
        int next_j = here[1] + delta[i][1];

        if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C) continue;
        int next_ = (int)board[next_i][next_j] - 'A';

        if (visited[next_] == 0){
            visited[next_] = 1;
            dfs({next_i, next_j}, ans+1);
            visited[next_] = 0;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    visited = vector<int>(26,0);

    for (int i = 0; i < R; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; ++j)
            board[i][j] = s[j];
    }

    visited[(int)board[0][0]-'A'] = 1;
    dfs({0, 0}, 1);

    cout << mx ;

    return 0;
}