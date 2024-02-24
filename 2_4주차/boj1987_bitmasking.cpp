#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<int>> board;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
int mx = 0;

void dfs(pair<int, int> here, int visited, int cnt){

    if (mx < cnt) mx = cnt;

    for(auto&d : delta){

        int next_i = here.first + d[0];
        int next_j = here.second+ d[1];

        if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C) continue;

        if ((visited&board[next_i][next_j])==0)
            dfs({next_i,next_j}, visited|board[next_i][next_j], cnt+1);
    }


    return;
}


int main(){
    cin >> R >> C;
    board = vector<vector<int>>(R, vector<int>(C,0));

    for(int i = 0 ; i < R; ++i){
        string s; cin >> s;
        for(int j = 0 ; j < C ; ++j){
            board[i][j] = 1<<(s[j]-'A');
        } 
    }


    dfs({0,0}, board[0][0], 1 );
    cout << mx;


    return 0;
}