#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> C, Copied_C, visited;
map<pair<int, int>, int> cheeze;
vector<int> delta[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(pair<int, int>here){
    visited[here.first][here.second] = 1;

    for(auto d : delta){
        int next_i = here.first+d[0];
        int next_j = here.second+d[1];

        if (next_i < 0 || next_j < 0 || next_i>=N || next_j >= M) continue;
        if (visited[next_i][next_j] == 1) continue;
        if (Copied_C[next_i][next_j] == 1){
            // outer
            cheeze[{next_i, next_j}] = 0;
            continue;
        }
        else dfs({next_i, next_j});
    }
    return;
}

int melt(){

    Copied_C = C;
    visited = vector<vector<int>>(N, vector<int>(M,0));

    dfs({0,0});

    int ans = 0;
    for(auto it = cheeze.begin(); it!=cheeze.end(); ++it){
        if (it->second == 0){
            Copied_C[it->first.first][it->first.second] = 0;
        }
        else{
            ans++;
        }
    }
    C = Copied_C;
    return ans;
}

int main(){
    cin >> N >> M;
    C.resize(N, vector<int>(M,0));

    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < M ; ++j){
            cin >> C[i][j];
            if (C[i][j] == 1){
                cheeze[{i,j}]=1;
            }
        }
    }


    int cnt =0;
    int remain = cheeze.size();
    while(1){
        cnt++;
        // 치즈 녹이기
        int temp = melt();
        if (temp){
            remain = temp;
        }
        else{
            break;
        }
    }

    cout << cnt << "\n" << remain << "\n";


    return 0;
}