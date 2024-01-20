#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
4
106 93  121 10
61  48  32  9
70  150 11  13
62  38  16  10
*/
int N;
vector<vector<int>> grid;
vector<vector<int>> DP;
vector<vector<int>> deltas = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int DFS(int i , int j){

    if (DP[i][j] != 0){
        return DP[i][j]; // DFS의 호출스택 최상단의 탈출 조건 , 메모이제이션을 통해 너무 깊이 들어가지 않아도 됨을 알려줌
    }
    
    else{

        for(auto d : deltas){
            int next_i = i + d[0];
            int next_j = j + d[1];

            if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N){

                if (grid[i][j] < grid[next_i][next_j]){
                    DP[i][j] = max(DP[i][j], DFS(next_i, next_j)+1);
                }

            }
        }
    }
    return DP[i][j]; // DFS의 최종 출력
}


int main(){

    cin >> N;
    grid = vector<vector<int>>(N, vector<int>(N,0));
    DP = vector<vector<int>>(N, vector<int>(N,0));

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> grid[i][j];
        }
    }

    int max_step = 0;
    for(int i = 0 ; i < N; ++i){
        for(int j =0 ; j < N ; ++j){
            if(DP[i][j] != 0)
                continue;
            
            DP[i][j] = DFS(i, j);
    
            if (max_step < DP[i][j])
                max_step = DP[i][j];
        }
    }
   

    cout << max_step << endl;



}