#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> B;
vector<vector<int>> ROT;

void rcs(int r, int c, int s, vector<vector<int>>& B){

    vector<vector<int>> tempB = B;
    // 가장 윗쪽 윗 칸 (r-s, c-s)
    // 가장 오른쪽 아랫 칸 (r+s, c+s)
    // 정사각형을 시계방향으로 한 칸씩 돌린다.

    for(int ss = 0 ; ss < s; ++ss){
        int s_i = r-s+ss;
        int e_i = r+s-ss;
        int s_j = c-s+ss;
        int e_j = c+s-ss;

        // 윗줄
        for(int j = e_j ; j > s_j ; --j){
            tempB[s_i][j] = B[s_i][j-1];
        } 

        // 오른쪽 줄
        for(int i = e_i ; i > s_i ; --i){
            tempB[i][e_j] = B[i-1][e_j];
        }

        // 아래줄
        for(int j = s_j; j < e_j ; ++j){
            tempB[e_i][j] = B[e_i][j+1];
        }

        // 왼쪽 줄
        for(int i = s_i ; i < e_i; ++i){
            tempB[i][s_j] = B[i+1][s_j];
        }
    }

    B = tempB;

    return;

}

void debug(vector<vector<int>>& BB){

    for(int i = 1 ; i <= N ; ++i){
        for(int j = 1; j <= M ; ++j) cout << BB[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    

}

int value(vector<vector<int>>& B){

    int mn = 500*100;
    for(int i  = 1; i <= N ; ++i){
        int sum = 0;
        for(int j = 1 ; j <= M ; ++j){
            sum += B[i][j];
        }
        if (mn > sum) mn = sum;
    }
    return mn;
}


int main(){

    cin >> N >> M >> K;
    B = vector<vector<int>>(N+1, vector<int>(M+1,0));

    for(int i = 1 ; i <= N ; ++i){
        for(int j = 1; j <= M ; ++j){
            cin >> B[i][j];
        }
    }

    ROT = vector<vector<int>>(K, vector<int>(3,0));
    for(int i = 0 ; i < K; ++i){
        cin >> ROT[i][0] >> ROT[i][1] >> ROT[i][2];
    }

    sort(ROT.begin(), ROT.end());

    int ans = 500*100;
    do{
        vector<vector<int>> BB = B;
        for(auto r : ROT){
            // cout << r[0] << r[1] << r[2] << endl;
            rcs(r[0], r[1], r[2], BB);
        }
        // debug(BB);
        int ret = value(BB);
        if (ans > ret) ans = ret;

    }while(next_permutation(ROT.begin(), ROT.end()));

    cout << ans ;

    return 0;
}