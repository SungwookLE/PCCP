#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maze(3, vector<int>(3,0));
vector<int> delta[4] = {{-1,0}, {1,0},{0,-1}, {0,1}};
vector<vector<int>> visited(3, vector<int>(3,0));

void dfs(pair<int, int>now){
    cout << now.first << " " << now.second << endl;
    visited[now.first][now.second] =1;

    for(auto d : delta){

        pair<int, int> next_now = {now.first+d[0], now.second+d[1]};
        if (next_now.first < 0 || next_now.first >=3 || next_now.second <0 || next_now.second >=3) continue;

        if (maze[next_now.first][next_now.second] == 1){
            if (visited[next_now.first][next_now.second]==0)
                dfs(next_now);
        }
    }

    return;
}

int main(){
    for(int i =0 ; i < 3 ; ++i){
        for(int j =0 ; j < 3; ++j){
            cin >> maze[i][j]; // 1: can go / 0: cant
        }
    }

    pair<int,int> S = {0,0};

    dfs(S);




    return 0;
}