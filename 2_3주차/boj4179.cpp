#include <bits/stdc++.h>

using namespace std;
int R, C;
vector<vector<char>> maze;
pair<int, int> jihun;
vector<pair<int, int>> fire;
vector<vector<int>> delta = {{0,-1},{1,0},{0,1},{-1,0}};
vector<vector<int>> visited;
set<int> ret;

void dfs(pair<int, int>J, int step){
    step+=1;

    // cout << "DEBUG: " << step << ", (" << J.first <<"," << J.second << ")" << endl;
    // for(int i = 0 ; i < R ; ++i){
    //     for(int j = 0 ; j < C ; ++j){
    //         if (i ==J.first && j == J.second) cout << "J";
    //         else cout << maze[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    if (J.first == 0 || J.second == 0 || J.first == R-1 || J.second == C-1){
        ret.insert(step);
        return;
    }

    // 1. 맵 업데이트
    int cnt = 0;
    int s = fire.size();
    for(int q = 0 ;  q < s ; ++q ){

        for(int p = 0 ; p < 4 ; ++p){
            int nextF_i = fire[q].first + delta[p][0];
            int nextF_j = fire[q].second+ delta[p][1];

            if (nextF_i >=0 && nextF_j >=0 && nextF_i < R && nextF_j < C){
                if (maze[nextF_i][nextF_j] == '.' || maze[nextF_i][nextF_j] == 'J'){
                    maze[nextF_i][nextF_j] = 'F';
                    fire.push_back({nextF_i, nextF_j});
                    cnt ++;
                }
            }
        }
    }

    // 2. dfs 호출 propagation
    for(auto d : delta){
        int next_i = J.first + d[0];
        int next_j = J.second+ d[1];
        if (next_i >= 0 && next_j >= 0 && next_i < R && next_j < C){
            if (visited[next_i][next_j] == 0 && maze[next_i][next_j] == '.'){
                visited[next_i][next_j] = 1; // 방문 처리
                dfs({next_i, next_j}, step);
                visited[next_i][next_j] = 0; // 방문 원복
            }
        }
    }

    // 3. 맵 원복
    while(cnt>0){
        pair<int, int> b = fire.back();
        fire.pop_back();
        maze[b.first][b.second] = '.';
        cnt--;
    }
}



int main(){
    cin >> R >> C;
    maze = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<int>>(R, vector<int>(C, 0));

    string s;
    for(int i = 0 ; i <R ; ++i){
        cin >> s;
        for(int j = 0 ; j < C ; ++j){
            maze[i][j] = s[j];
            if (maze[i][j] == 'J')
                jihun = {i,j};
            else if (maze[i][j] == 'F')
                fire.push_back({i,j});
        } 
    }

    visited[jihun.first][jihun.second] = 1;
    dfs(jihun, 0);

    if (!ret.empty()){
        cout << *ret.begin();
    }
    else
        cout <<"IMPOSSIBLE";

    return 0;
}