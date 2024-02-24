#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
// vector<int> visited;
map<char, int> visited;

int mx = 0;

void dfs(pair<int, int> here, int cnt){

    if (mx < cnt) mx = cnt;

    for(auto& d : delta){
        int next_i = here.first + d[0];
        int next_j = here.second+ d[1];

        if (next_i<0 || next_j <0 || next_i >= R || next_j >= C) continue;

        if (visited[board[next_i][next_j]] == 0){
            visited[board[next_i][next_j]] = 1;
            dfs({next_i, next_j}, cnt+1);
            visited[board[next_i][next_j]] = 0;
        }
    }

    return;
}

int main(){

    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));

    for(int i = 0 ; i < R; ++i){
        string s; cin >> s;
        for(int j = 0 ; j < C ; ++j) board[i][j] = s[j];
    }

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0 ; i < s.size(); ++i) visited[s[i]] = 0;

    visited[board[0][0]] = 1;
    dfs({0,0}, 1);

    cout << mx;

    return 0;
}