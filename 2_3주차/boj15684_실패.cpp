#include <bits/stdc++.h>

using namespace std;

int N, M, H;
vector<vector<int>> ladder;
vector<vector<int>> visited;
vector<vector<int>> delta = {{0,-1},{0,1},{1,0}};
vector<int> ret;

bool dfs(pair<int, int> here, pair<int, int> goal){
    bool ret = false;
    visited[here.first][here.second] = 1;

    if (here.first == H+1){
        return true;   
    }

    for(auto& d : delta){
        int next_i= here.first+d[0];
        int next_j= here.second+d[1];
        if (next_i>=1 && next_j>=1 && next_i <= H+1 && next_j < 2*N){

            if (visited[next_i][next_j] == 0 && ladder[next_i][next_j] == 1){
                ret = dfs({next_i, next_j}, goal);
                if (ret) return ret;
            }
        }
    }

    return false;
}

void make_combi(int start_i, int start_j, int r, vector<vector<int>> add){

    if (add.size()-M == r){
        for(auto ad: add){
            ladder[ad[0]][ad[1]] = 1;
        }

        // cout <<">>>> (ladder: " << r << ")\n";
        // for(auto ll: ladder){
        //     for(auto l : ll) cout << l << " ";
        //     cout << endl;
        // }
        // cout << endl;

        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            // start: ladder[1][i*2-1]
            //  goal: ladder[H][i*2-1]

            dfs({1, i*2-1}, {H, i*2-1});
            if (visited[H+1][i*2-1]) cnt ++;


            // cout << ">>>> (visited)\n";
            // for(auto ll: visited){
            //     for(auto l : ll) cout << l << " ";
            //     cout << endl;
            // }

            visited = vector<vector<int>>(H+2, vector<int>(2*N,0));
        }

        if (cnt == N){
            ret.push_back(r);
        }

        for(auto ad: add){
            ladder[ad[0]][ad[1]] = 0;
        }

        return;
    }

    for(int i = start_i+1; i <= H ; ++i){
        for(int j = start_j+1; j < N ; ++j){

            int p = 2*j;

            if (add.size()){
                if (add.back()[0] != i){
                    add.push_back({i,p});
                    make_combi(i, 0, r, add);
                    add.pop_back();
                }
            }

            else{
                add.push_back({i,p});
                make_combi(i, 0, r, add);
                add.pop_back();
            }
        }
    }


}

int main(){

    cin >> N >> M >> H;

    ladder = vector<vector<int>>(H+2, vector<int>(2*N,0));
    visited = vector<vector<int>>(H+2, vector<int>(2*N,0));

    for(int i = 1 ; i <= H+1; ++i){
        for(int j =1 ; j <= N; ++j){
            ladder[i][2*j-1] = 1;
        }
    }

    int a, b;
    vector<vector<int>> add;
    for(int i = 0; i < M ;++i){
        cin >> a >> b;
        ladder[a][2*b] = 1;
        add.push_back({a, 2*b});
    }

    // 놓을 수 있는 가로선의 개수 (N-1)*H
    // 인접하게 가로선을 둘 순 없다.
    for(int ans = 0; ans <= 3; ans++){
        make_combi(0, 0, ans, add);
    }

    if (ret.empty())
        cout << -1 << endl;
    else    cout << ret[0] << endl;


    return 0 ;
}