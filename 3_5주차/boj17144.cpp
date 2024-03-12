#include <bits/stdc++.h>

using namespace std;

int R, C, T;
vector<vector<int>> room;
vector<pair<int, int>> cleaner;

void dust_diffusion(vector<vector<int>>& room){

    vector<vector<int>> next_room = room;
    vector<vector<int>> delta = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    for(int i = 0 ; i < R ; ++i){
        for(int j = 0 ; j < C ; ++j){

            if (room[i][j] != -1 && room[i][j] != 0){
                int cnt = 0;
                for(auto&d : delta){
                    int next_i = i + d[0];
                    int next_j = j + d[1];

                    if (next_i < 0 || next_j < 0 || next_i >= R || next_j >= C) continue;
                    if (room[next_i][next_j] == -1) continue;

                    next_room[next_i][next_j] += room[i][j]/5;
                    cnt++;
                }
                next_room[i][j] -= cnt*(room[i][j]/5);
            }
        }
    }

    room = next_room;
}

void circulation(vector<vector<int>>& room, vector<pair<int, int>>& c){
    vector<vector<int>> next_room = room;

    pair<int, int> upper_start = c[0];
    pair<int, int> under_start = c[1];

    
    // ** upper circulation
    for(int i = upper_start.first; i > 0 ; --i){
        next_room[i][0] = room[i-1][0];
        if (i==upper_start.first) next_room[i][0] = -1; // 공청기로 진입함
    }
    for(int i = 0 ; i < C-1; ++i){
        next_room[0][i] = room[0][i+1];
    }
    for(int i = 0 ; i < upper_start.first; ++i){
        next_room[i][C-1] = room[i+1][C-1];
    }
    for(int i = C-1 ; i > 0 ; --i){
        next_room[upper_start.first][i] = room[upper_start.first][i-1];
        if (i==1) next_room[upper_start.first][i] = 0; // 공청기에서 나옴
    }


    // ** upper circulation
    for(int i = under_start.first; i < R-1 ; ++i){
        next_room[i][0] = room[i+1][0];
        if (i==under_start.first) next_room[i][0] = -1; // 공청기로 진입함
    }
    for(int i = 0 ; i < C-1; ++i){
        next_room[R-1][i] = room[R-1][i+1];
    }
    for(int i = R-1 ; i > under_start.first; --i){
        next_room[i][C-1] = room[i-1][C-1];
    }
    for(int i = C-1 ; i > 0 ; --i){
        next_room[under_start.first][i] = room[under_start.first][i-1];
        if (i==1) next_room[under_start.first][i] = 0; // 공청기에서 나옴
    }


    room = next_room;
}

int count_dust(vector<vector<int>>& room){
    int cnt = 0;
    for(int i = 0 ; i < R ; ++i){
        for(int j = 0 ; j < C ; ++j){
            if (room[i][j] != -1 && room[i][j] != 0)
                cnt += room[i][j];
        }
    }

    return cnt;
}

int main(){
    cin >> R >> C >> T;
    
    room = vector<vector<int>>(R, vector<int>(C,0));

    for(int i = 0 ; i < R ; ++i){
        for(int j = 0 ; j < C ; ++j){


            cin >> room[i][j];

            if (room[i][j] == -1){
                cleaner.push_back({i,j});
            }

        }
    }

    for(int i =0 ; i < T ; ++i){
        dust_diffusion(room);
        circulation(room, cleaner);
    }



    cout << count_dust(room);    


    return 0;
}