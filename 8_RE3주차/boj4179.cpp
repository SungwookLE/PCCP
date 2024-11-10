#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<int>> Fires;
vector<int> J;
queue<vector<int>> J_candidates, F_candidates;
vector<vector<int>> J_searched, F_searched;
vector<int> delta[4] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<char>> maze;
#define INF 1000000000
int main(){

    cin >> R >> C;
    maze = vector<vector<char>>(R, vector<char>(C));
    J_searched = vector<vector<int>>(R, vector<int>(C,0));
    F_searched = vector<vector<int>>(R, vector<int>(C,INF));

    for(int i = 0 ; i < R ; ++i){
        for(int j =0 ; j < C ; ++j){
            cin >> maze[i][j];
            if (maze[i][j] == 'F'){
                Fires.push_back({i,j});
            }
            if (maze[i][j] == 'J'){
                J = {i,j};
                maze[i][j] = '.';
            }
        }
    }
    // 미로를 탈출할 수 있는 경우에 가장 빠른 탈출시간?
        // BFS 로 풀어야할 듯 (가장 빠른 탈출시간)
        // 먼저, 불이 퍼지는 시간을 기록해둔 뒤, 시간을 비교해서 지훈의 탐색공간 BFS


    for(auto f : Fires){
        F_candidates.push(f);
        F_searched[f[0]][f[1]] = 1;
    }

    while(F_candidates.size()){
        auto here = F_candidates.front();
        F_candidates.pop();

        for(auto d : delta){
            int next_i = here[0]+d[0];
            int next_j = here[1]+d[1];

            if (next_i <0 || next_j < 0 || next_i >= R || next_j >= C) continue;
            if (F_searched[next_i][next_j] != INF ) continue;
            if (maze[next_i][next_j] == '.' || maze[next_i][next_j] == 'J'){
                F_candidates.push({next_i, next_j});
                F_searched[next_i][next_j] = F_searched[here[0]][here[1]]+1;
            }
        }
    }


    J_candidates.push(J);
    J_searched[J[0]][J[1]] = 1;

    while(J_candidates.size()){
        auto here = J_candidates.front();
        J_candidates.pop();

        if (here[0] == 0 || here[0] == R-1 || here[1] == 0 || here[1] == C-1){
            cout << J_searched[here[0]][here[1]] ;
            return 0;
        }
        
        for(auto d : delta){
            int next_i = here[0] + d[0];
            int next_j = here[1] + d[1];

            if (next_i <0 || next_j < 0 || next_i >= R || next_j >= C) continue;
            if (J_searched[next_i][next_j] != 0) continue;
            if (maze[next_i][next_j] != '.') continue;
            
            // 이 조건문이 제일 중요하다
            if (J_searched[here[0]][here[1]] + 1 < F_searched[next_i][next_j]){
                J_candidates.push({next_i, next_j});
                J_searched[next_i][next_j] = J_searched[here[0]][here[1]]+1;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}