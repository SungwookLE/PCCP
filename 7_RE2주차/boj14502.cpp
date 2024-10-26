#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> R, R_cpy;
vector<pair<int, int>> S;
vector<pair<int, int>> E, W;
vector<vector<int>> C;

void PickThree(vector<int>P, int start){
    if (P.size()==3){
        C.push_back(P);
        return;
    }
    for(int i =start+1 ; i < E.size(); ++i){
        P.push_back(i);
        PickThree(P, i);
        P.pop_back();
    }
}

vector<int> delta[4] = {{-1,0}, {1,0},{0,-1},{0,1}};
vector<vector<int>> visited;

void dfs(pair<int, int> s){
    visited[s.first][s.second] = 1;
    R_cpy[s.first][s.second] = 2;

    for(auto d : delta){
        int next_i = s.first +d[0];
        int next_j = s.second+d[1];

        if (next_i <0 || next_j < 0 || next_i >=N || next_j>=M) continue;
        if (R_cpy[next_i][next_j] == 1 || R_cpy[next_i][next_j] == 2) continue;
        if (visited[next_i][next_j] == 1) continue;;

        dfs({next_i, next_j});
    }

    return;
}

int ans = 0;

void simul(){
    // dfs
    // count

    visited = vector<vector<int>>(N, vector<int>(M,0));
    R_cpy = R;
    for(auto s: S){
        dfs(s);
    }

    int cnt = 0;
    for(auto rr: R_cpy){
        for(auto r : rr){
            if (r == 0){
                cnt++;
            }
        }
    }


    if (ans < cnt){
        ans = cnt;
    }

    return;
}

int main(){
    cin >> N >> M;
    R.resize(N, vector<int>(M,0));
    visited.resize(N, vector<int>(M,0));


    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < M ; ++j){
            cin >> R[i][j];
            if (R[i][j] == 2){
                S.push_back({i,j});
            }
            else if (R[i][j] == 0){
                E.push_back({i,j});
            }
            else{
                W.push_back({i,j});
            }
        }
    }

    PickThree({},-1);
        
    for(auto c: C){
        for(int i =0 ; i < c.size(); ++i) R[E[c[i]].first][E[c[i]].second] = 1;
        simul(); // dfs and count zero
        for(int i =0 ; i < c.size(); ++i) R[E[c[i]].first][E[c[i]].second] = 0;
    }

    cout << ans << endl;

    return 0;
}