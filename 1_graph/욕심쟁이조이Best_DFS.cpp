#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
4
106 93  121 10
61  48  32  9
70  150 11  13
62  38  16  10
*/
int N;
vector<vector<int>> farm;
vector<vector<int>> deltas = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> dp;


int DFS(int i, int j ){

    // memoization
    if (dp[i][j] != 0)
        return dp[i][j];

    for(auto d : deltas){
        int next_i = i+d[0];
        int next_j = j+d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < N){

            if (farm[next_i][next_j] >= farm[i][j])
                dp[i][j] = max(dp[i][j], DFS(next_i, next_j) + 1);
        }
    }
    return dp[i][j];
}





int main(){

    cin >> N;
    farm = vector<vector<int>>(N, vector<int>(N,0));
    dp = vector<vector<int>>(N, vector<int>(N,0));

    for(int i =0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> farm[i][j];
        }
    }

    for(int i =0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            // memoization
            if (dp[i][j] != 0)
                continue;
            dp[i][j] = DFS(i, j);
        }
    }

    return 0;
}