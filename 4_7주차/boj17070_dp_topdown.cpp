#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> S;
vector<vector<int>> delta = {{0,1}, {1,0}, {1,1}};
int DP[17][17][3]; // 초기화

int go(pair<int, int> here, int direction){
    
    if (here.first == N-1 && here.second == N-1){
        return 1; // 기저사례
    }

    if (DP[here.first][here.second][direction]){
        return DP[here.first][here.second][direction]; // 메모이제이션
    }

    for(int i =0 ; i < 3 ; ++i){
        if (direction==0){
            if(i==1) continue;
        }
        if (direction==1){
            if(i==0) continue;
        }

        int next_i = here.first+delta[i][0];
        int next_j = here.second+delta[i][1];

        if (next_i <0 || next_i >=N) continue;
        if (next_j <0 || next_j >=N) continue;

        if (S[next_i][next_j] == 1) continue;
        if (i==2){
            if (S[next_i-1][next_j] == 1) continue;
            if (S[next_i][next_j-1] == 1) continue;
        }

        // 로직
        DP[here.first][here.second][direction] += go({next_i, next_j}, i);
    }

    return DP[here.first][here.second][direction];
}


int main(){
    cin >> N;
    S = vector<vector<int>>(N, vector<int>(N));
    for(int i = 0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j) cin >> S[i][j];
    }

    cout << go({0,1}, 0) << endl;

    return 0;
}