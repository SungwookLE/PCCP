#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> cheeze, prevCheeze;
vector<vector<int>> visited;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int i, int j, int& count){

    count+=1;
    visited[i][j] = 1;
    for(auto d : delta){
        int next_i = i + d[0];
        int next_j = j + d[1];
        if (next_i >= 1 && next_j >= 1 && next_i < N-1 && next_j < M-1){
            if (cheeze[next_i][next_j] == 1){
                prevCheeze[next_i][next_j] = 0;
            }
        }
    }

    for(auto d : delta){
        int next_i = i + d[0];
        int next_j = j + d[1];

        if ( next_i >= 0 && next_j >= 0 && next_i < N && next_j < M){
            if (visited[next_i][next_j] == 0 && cheeze[next_i][next_j] == 0)
                dfs(next_i, next_j, count);
        }
    }

    return;
}

int countCheeze(){
    int cnt = 0;
    for(auto cc: cheeze){
        for(auto c: cc){
            if (c==1) cnt++;
        }
    }
    return cnt;
}



int main(){
    cin >> N >> M;
    cheeze = vector<vector<int>>(N, vector<int>(M,0)); // 치즈1, 공기0

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0; j <M ; ++j){
            cin >> cheeze[i][j];
        }
    }
    prevCheeze = cheeze;


    int days = 0;
    vector<int> rem;
    while(true){
        visited = vector<vector<int>>(N, vector<int>(M,0));
        int count = 0;
        dfs(0, 0, count);
        rem.push_back(countCheeze());
        if(count == N*M)
            break;

        cheeze= prevCheeze;
        days++;
    }

    rem.pop_back();
    cout << days << "\n" << rem.back() << "\n";


    return 0;
}