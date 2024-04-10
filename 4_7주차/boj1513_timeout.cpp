#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M, C;
pair<int, int> start, goal;
vector<vector<int>> G;
vector<pair<int, int>> c;
typedef long long ll;
vector<vector<int>> delta = {{1,0}, {0,1}};
vector<bool> V;

int go(pair<int, int> here, int cnt, vector<bool> visited){

    int ret = 0;
    int idx = -1;
    for(int i =0 ; i < C ; ++i){
        if (here.first == c[i].first && here.second == c[i].second){
            
            for(int j = i ; j < C ; ++j){
                if (visited[j] == 1) return 0;
            }

            visited[i] = 1;
            idx = i;
            break;
        }
    }

    int vCnt = 0;
    for(int i = 0 ; i < C; ++i){
        if (visited[i] == 1) vCnt ++;
    }

    if (here.first == goal.first && here.second == goal.second){
        if(vCnt == cnt){
            return 1;
        }
    }
   

    for(auto d : delta){
        int next_i = here.first + d[0];
        int next_j = here.second+ d[1];

        if (next_i <= 0 || next_i > N) continue;
        if (next_j <= 0 || next_j > M) continue;

        ret += go({next_i, next_j}, cnt, visited);
    }

    if (idx != -1) visited[idx] = 0;

    return ret;
}



int main(){
    cin >> N >> M >> C;

    start = {1,1};
    goal  = {N,M};

    G = vector<vector<int>>(N+1, vector<int>(M+1,0));
    c = vector<pair<int, int>>(C);


    for(int i = 0; i < C; ++i){
        cin >> c[i].first >> c[i].second;
    }


    for(int i =0 ; i <= C; ++i){
        V = vector<bool>(C,0);
        cout <<  go({1,1}, i, V) << " ";
    }
    cout << endl;




    return 0;
}