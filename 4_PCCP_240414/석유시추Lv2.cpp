#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
vector<vector<int>> visited;
map<int, int> oil;

vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
int N, M;

int dfs(pair<int, int> here, int id, vector<vector<int>>& land){

    int ret = 0 ;
    visited[here.first][here.second] = id;

    for(auto d : delta){

        int next_i = here.first + d[0];
        int next_j = here.second+ d[1];

        if (next_i < 0 || next_i >= N) continue;
        if (next_j < 0 || next_j >= M) continue;
        if (land[next_i][next_j] == 0) continue;
        if (visited[next_i][next_j] != 0) continue;

        ret += (dfs({next_i, next_j}, id, land)+1);

    }

    return ret;
}



int solution(vector<vector<int>> land) {
    int answer = 0;

    N = land.size();
    M = land[0].size();


    //fluid fill 을 먼저 해두자

    int id = 1;
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i =0 ; i < N; ++i){
        for(int j = 0; j < M; ++j){

            if (land[i][j] == 1 && visited[i][j] == 0){
                int count = dfs({i,j}, id, land)+1;        
                oil[id] = count;
                id ++;
            }
        }
    }

    for(int j = 0; j < M; ++j){
        vector<int> checked(id, 0);
        int oil_sum = 0;
        for(int i = 0 ; i < N; ++i){
            if (visited[i][j] != 0 && checked[visited[i][j]] == 0 ){
                checked[visited[i][j]] = 1;
                oil_sum += oil[visited[i][j]];
            }
        }
        answer = max(answer, oil_sum);
    }



    return answer;
}