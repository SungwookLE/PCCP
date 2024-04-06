#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> S;
vector<vector<int>> delta = {{0,1}, {1,0}, {1,1}};
int DP[17][17][3];


bool canGo(pair<int, int> here, int direction){
    int next_i = here.first + delta[direction][0];
    int next_j = here.second + delta[direction][1];

    if (next_i < 0 || next_i >= N) return false;
    if (next_j < 0 || next_j >= N) return false;

    if (S[next_i][next_j] == 1) return false;

    if (direction==2){
        if (S[next_i-1][next_j] == 1) return false;
        if (S[next_i][next_j-1] == 1) return false;
    }

    return true;
}


int main(){
    cin >> N;
    S = vector<vector<int>>(N, vector<int>(N));
    for(int i = 0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j) cin >> S[i][j];
    }

    // 점화식 풀이 (DP)
    DP[0][1][0] = 1; // 초기 위치
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            // 가로로 놓여져 있는 위치에서 -> {가로, 대각선}으로 갈수 있는 것에 대한 경우의 수
            if (canGo({i,j}, 0)) DP[i+delta[0][0]][j+delta[0][1]][0] += DP[i][j][0];
            if (canGo({i,j}, 2)) DP[i+delta[2][0]][j+delta[2][1]][2] += DP[i][j][0];

            // 세로 놓여져 있는 위치에서 -> {세로, 대각선}으로 갈수 있는 것에 대한 경우의 수
            if (canGo({i,j}, 1)) DP[i+delta[1][0]][j+delta[1][1]][1] += DP[i][j][1];
            if (canGo({i,j}, 2)) DP[i+delta[2][0]][j+delta[2][1]][2] += DP[i][j][1];

            // 대각선으로 놓여져 있는 위치에서 -> {가로, 세로, 대각선}으로 갈수 있는 것에 대한 경우의 수
            if (canGo({i,j}, 0)) DP[i+delta[0][0]][j+delta[0][1]][0] += DP[i][j][2];
            if (canGo({i,j}, 1)) DP[i+delta[1][0]][j+delta[1][1]][1] += DP[i][j][2];
            if (canGo({i,j}, 2)) DP[i+delta[2][0]][j+delta[2][1]][2] += DP[i][j][2];
        }
    }

    cout << DP[N-1][N-1][0] + DP[N-1][N-1][1] + DP[N-1][N-1][2];


    return 0;
}