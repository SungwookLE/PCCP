#include <bits/stdc++.h>

using namespace std;

int N, M, Walls;
vector<vector<int>> maze;
vector<pair<int, int>> virus;
vector<vector<int>> visited;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> space;
vector<vector<vector<int>>> wallcombi;



void dfs(int i, int j, int& count){
    count +=1;
    visited[i][j] = 1;

    for(auto d : delta){
        int next_i = i + d[0];
        int next_j = j + d[1];

        if(next_i >=0 && next_j >=0 && next_i < N && next_j < M){
            if(maze[next_i][next_j] == 0 && visited[next_i][next_j] == 0)
                dfs(next_i, next_j, count);
        }

    }

    return;
}

void make_combi(int start, int r, vector<vector<int>> ret){

    if (ret.size() == r){
        wallcombi.push_back(ret);
        return;
    }

    for(int i = start+1; i < space.size(); ++i){
        ret.push_back(space[i]);
        make_combi(i, r, ret);
        ret.pop_back();
    }

    return;
}


int main(){

    cin >> N >> M;
    maze = vector<vector<int>>(N, vector<int>(M,0));
    visited = vector<vector<int>>(N, vector<int>(M,0));

    // 0은 빈칸, 1은 벽, 2는 바이러스 위치 
    // 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수
    for(int i =0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j){
            cin >> maze[i][j];
            if (maze[i][j] == 2) virus.push_back({i,j});
            else if (maze[i][j] == 1) Walls++;
            else if (maze[i][j] == 0) space.push_back({i,j});
        }

    
    make_combi(-1, 3, {});
    int mx = -1;

    for(auto w: wallcombi){
        visited = vector<vector<int>>(N, vector<int>(M,0));

        maze[w[0][0]][w[0][1]]=1;
        maze[w[1][0]][w[1][1]]=1;
        maze[w[2][0]][w[2][1]]=1;

        int ret = 0;

        for(auto v : virus){
            dfs(v.first, v.second, ret);
        }
        mx = max(mx, N*M - ret - Walls - 3);

        maze[w[0][0]][w[0][1]]=0;
        maze[w[1][0]][w[1][1]]=0;
        maze[w[2][0]][w[2][1]]=0;


    }

    cout << mx << endl;


    return 0;
}