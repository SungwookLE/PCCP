#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> lake;
queue<vector<int>> candidates_Swan, candidates_SwanTemp;
queue<vector<int>> candidates_Water, candidates_WaterTemp;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> visitedSwan, visitedWater;

bool moveSwan(){
    vector<int> now;
    while(candidates_Swan.size()){
        now = candidates_Swan.front(); candidates_Swan.pop();

        for(auto d : delta){
            int next_i = now[0]+d[0];
            int next_j = now[1]+d[1];

            if (next_i >= 0 && next_j >= 0 && next_i < R && next_j < C){

                if (visitedSwan[next_i][next_j] == 0){
                    visitedSwan[next_i][next_j] = 1;
                    if (lake[next_i][next_j] == '.'){
                        candidates_Swan.push({next_i, next_j});
                    }
                    else if (lake[next_i][next_j] == 'X'){
                        candidates_SwanTemp.push({next_i, next_j});
                    }
                    else if (lake[next_i][next_j] == 'L') return true;
                }
            }
        }
    }

    return false;
}

void waterMelting(){
    vector<int> now;
    while(candidates_Water.size()){
        now = candidates_Water.front(); candidates_Water.pop();

        for(auto d : delta){
            int next_i = now[0] + d[0];
            int next_j = now[1] + d[1];

            if (next_i >= 0 && next_j >= 0 && next_i < R && next_j < C){
                
                if (visitedWater[next_i][next_j] == 0){

                    if (lake[next_i][next_j] == 'X'){
                        candidates_WaterTemp.push({next_i, next_j});
                        visitedWater[next_i][next_j] = 1;
                        lake[next_i][next_j] = '.';
                    }
                }
            }
        }
    }

    return;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    lake = vector<vector<char>>(R, vector<char>(C));
    visitedSwan = vector<vector<int>>(R, vector<int>(C,0));
    visitedWater = vector<vector<int>>(R, vector<int>(C,0));

    for(int i = 0 ; i < R ; ++i){
        string s;
        cin >> s;
        for(int j = 0 ; j < C; ++j){
            lake[i][j] = s[j];

            if (lake[i][j] == 'L' && candidates_Swan.empty()){
                candidates_Swan.push({i,j}); // 백조는 한마리 위치에서만 시작
                visitedSwan[i][j] = 1;
            }
            if (lake[i][j] == 'L' || lake[i][j] == '.'){
                candidates_Water.push({i,j});
                visitedWater[i][j] = 1;
            }
        }
    }

    int day = 0;
    while(true){

        if (moveSwan()) break;
        waterMelting();

        // cout << endl;
        // for(auto ll : lake){
        //     for(auto l : ll) cout << l;
        //     cout << endl;
        // }
        // cout << endl;

        candidates_Swan = candidates_SwanTemp;
        candidates_Water = candidates_WaterTemp;
        candidates_WaterTemp = queue<vector<int>>();
        candidates_SwanTemp = queue<vector<int>>();
        day++;
    }

    cout << day << "\n";
    return 0;
}