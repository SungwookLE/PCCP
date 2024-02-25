#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> m; // 벽: 서북동남
vector<vector<int>> mark;
vector<vector<int>> visited, visited2;
map<int, pair<int, int>> s;
vector<int> rooms(60*60,0);

int mx = 0, mx2 = 0;
vector<vector<int>> delta = {{0,-1},{-1,0},{0,1},{1,0}};


int dfs1(pair<int, int> here, int id){

    int ret = 1;
    visited[here.first][here.second] = 1;
    mark[here.first][here.second] = id;

    for(int i = 0 ; i < 4 ; ++i){
        int bit = m[here.first][here.second];

        if ((bit & (1<<i))) continue;

        int next_i = here.first + delta[i][0];
        int next_j = here.second+ delta[i][1];

        if (next_i < 0 || next_j < 0 || next_i >= M || next_j >= N) continue;
        if (visited[next_i][next_j] == 1) continue;

        ret+=dfs1({next_i, next_j}, id);
    }

    return ret;
}


void dfs2(pair<int, int> here, set<int>& ret){

    visited2[here.first][here.second] = 1;

    for(auto& d : delta){

        int next_i = here.first + d[0];
        int next_j = here.second+ d[1];

        if (next_i < 0 || next_j < 0 || next_i >= M || next_j >= N) continue;
        if (visited2[next_i][next_j] == 1) continue;

        if (mark[here.first][here.second] == mark[next_i][next_j])
            dfs2({next_i, next_j}, ret);
        else{
            ret.insert(mark[next_i][next_j]);
        }

    }




}

int main(){
    cin >> N >> M;
    m = vector<vector<int>>(M, vector<int>(N,0));
    mark = vector<vector<int>>(M, vector<int>(N,0));
    visited = vector<vector<int>>(M, vector<int>(N,0));
    visited2 = vector<vector<int>>(M, vector<int>(N,0));


    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> m[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < M ; ++i){
        for(int j =0 ; j < N ; ++j){
            if(visited[i][j] == 0){
                cnt++;
                int room = dfs1({i,j}, cnt);
                s[cnt] = {i,j};
                rooms[cnt] = room;


                if (mx < room) mx = room;
            } 
        }
    }

    // 3 번째 문제: 벽하나만 허물어서 최대 방사이즈를 구해라
    // 접근한 방식:
        // 어차피 무조건 이웃 방이어야지만 허물 수 있으니, 방마다의 자신의 이웃이 누구 있는지 체크하는 dfs2 함수를 만들자
        // dfs2 함수는 자신의 이웃이 누구인지 알려준다.
        // 이웃의 방을 더하면서 최대값을 갱신해준다.
        
    for(int i = 1 ; i <= cnt; ++i){

        set<int> ret ;
        dfs2(s[i], ret);
        
        int sum = rooms[i];
        for(auto r : ret){
            sum += rooms[r];
            if ( mx2 < sum) mx2 = sum;
            sum -= rooms[r];
        }
    }
    
    cout << cnt << "\n";
    cout << mx << "\n";
    cout << mx2 << "\n";

    return 0;
}