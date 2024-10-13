#include <bits/stdc++.h>

using namespace std;
int M, N, K; // 높이x너비, K개 직사각형
vector<vector<int>> paper, visited;
vector<int> delta[4] = {{-1,0},{1,0},{0,-1},{0,1}};

int dfs(vector<int> here){
    int number = 1;
    visited[here[0]][here[1]] = 1;
    
    for(auto d : delta){
        int next_i = here[0] + d[0];
        int next_j = here[1] + d[1];

        if (next_i < 0 || next_j < 0 || next_i >= M || next_j >= N) continue;
        if (visited[next_i][next_j] == 0 && paper[next_i][next_j] ==0){
            number += dfs({next_i, next_j});
        }
    }

    return number;
}

int main(){
    cin >> M >> N >> K;
    paper.resize(M, vector<int>(N,0));
    visited.resize(M, vector<int>(N,0));

    pair<int, int> LBo, RUp;
    for(int i =0 ; i < K ; ++i){
        cin >> LBo.second >> LBo.first;
        cin >> RUp.second >> RUp.first;


        for(int j = LBo.first; j < RUp.first; ++j){
            for(int k = LBo.second; k < RUp.second; ++k){
                paper[j][k]= 1;
            }
        }
    }

    int number = 0;
    vector<int> counts;
    for(int i = 0 ; i < M ; ++i){
        for(int j =0 ; j < N ; ++j){

            if (paper[i][j] == 0 && visited[i][j] == 0){
                number++;
                counts.push_back(dfs({i,j}));
            }
        }
    }

    cout << number << "\n";
    sort(counts.begin(), counts.end(), less<int>());
    for(auto c : counts) cout << c << " ";


    return 0;
}