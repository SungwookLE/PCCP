#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<char>> mmap;
vector<vector<int>> land;
vector<vector<vector<int>>> combi;
vector<int> delta[4] = {{-1,0},{1,0},{0,-1},{0,1}};


int bfs(vector<int> start){

    vector<int> S = start;

    queue<vector<int>> candidates;
    candidates.push(S);
    vector<vector<int>> searched(N, vector<int>(M,0));
    searched[S[0]][S[1]] = 1;
    
    while(candidates.size()){
        auto here = candidates.front();
        candidates.pop();

        for(auto& d : delta){
            int next_i = here[0] + d[0];
            int next_j = here[1] + d[1];

            if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M) continue;
            if (searched[next_i][next_j] != 0) continue;
            if (mmap[next_i][next_j] != 'L') continue;

            searched[next_i][next_j] = searched[here[0]][here[1]]+1;
            candidates.push({next_i,next_j});
        }
    }

    int mx = 0;
    for(auto ss : searched){
        for(auto s : ss){
            if (mx < s-1) mx = s-1;
        }
    }

    return mx;
}


int main(){
    string s;
    cin >> N >> M;

    mmap.resize(N, vector<char>(M));

    for(int i =0; i < N ; ++i){
        cin >> s;
        for(int j =0 ;j < M ; ++j){
            mmap[i][j] = s[j];
            if (mmap[i][j] == 'L') land.push_back({i,j});
        }
    }



    int mx = 0;
    for(auto l : land){
        int ret = bfs(l);
        // cout << ret << ": " << c[0][0] << ", " << c[0][1] << "     " << c[1][0] << ", " << c[1][1] << endl;
        if (ret > mx) mx = ret;
    }

    cout << mx << endl;

    return 0;
}