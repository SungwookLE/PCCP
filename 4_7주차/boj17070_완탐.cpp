#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> S;
vector<vector<int>> delta = {{0,1}, {1,0}, {1,1}};
vector<vector<int>> visited;


int go(pair<int, int> here, int direction){
    int ret = 0;
   if (here.first == N-1 && here.second == N-1){
        return 1; // 기저사례
   } 

   for(int i = 0 ; i < 3 ; ++i){

        if (direction==0){ if (i==1) continue;}
        else if (direction==1){ if (i==0) continue;}

        int next_i = here.first + delta[i][0];
        int next_j = here.second+ delta[i][1];

        if (next_i < 0 || next_i >= N) continue;
        if (next_j < 0 || next_j >= N) continue;
        if (S[next_i][next_j] == 1) continue;

        if (i==2){
            if (S[next_i-1][next_j] == 1) continue;
            if (S[next_i][next_j-1] == 1) continue;
        }

        if(visited[next_i][next_j] == 0){
             // 이걸 안해줘도 맞았던 이유가 delta 의 조건으로 인해 루프될 일이 없어서 그랬던 것임 (4/6)
            visited[next_i][next_j] = 1;
            ret += go({next_i, next_j}, i);
            visited[next_i][next_j] = 0;
        }
   }

   return ret;
}


int main(){
    cin >> N;
    S = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<int>>(N, vector<int>(N,0));


    for(int i = 0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j) cin >> S[i][j];
    }

 
    cout << go({0,1}, 0) << endl;

    return 0;
}