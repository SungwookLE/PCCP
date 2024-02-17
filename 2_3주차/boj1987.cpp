#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> board;
map<char, int> mp;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mx = 0;

void dfs(vector<int> here,map<char, int>& history, int ans)
{   
    if (mx < ans) mx = ans;

    for (auto d : delta)
    {
        int next_i = here[0] + d[0];
        int next_j = here[1] + d[1];

        if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C) continue;

        if (history[board[next_i][next_j]] == 0){
            history[board[next_i][next_j]] = 1;
            dfs({next_i, next_j}, history, ans+1);
            history[board[next_i][next_j]] = 0;
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
    
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
    for(int i = 0 ; i < alphabet.size() ; ++i) mp[alphabet[i]] = 0;

    for (int i = 0; i < R; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; ++j)
            board[i][j] = s[j];
    }

    mp[board[0][0]] = 1;
    dfs({0, 0}, mp, 1);

    cout << mx ;

    return 0;
}