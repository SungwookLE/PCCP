#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> W;
vector<int> visited;
int mn = 1E9;

void go(int here, int cost, int idx, int start){

    if (here == start && idx==N){
        if (mn > cost) mn = cost;
        return;
    }

    for(int i =0 ; i < N ; ++i){

        if(W[here][i] != 0){
            if (visited[i] == 0){
                visited[i] = 1;
                go(i, cost + W[here][i], idx+1, start);
                visited[i]= 0; // 원복
            }
        }
    }

    return;
}


int main(){
    cin >> N;

    W = vector<vector<int>>(N, vector<int>(N,0));
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            cin >> W[i][j];
        }
    }

    // dfs 시도
    for(int i =0 ; i < N ; ++i){
        visited = vector<int>(N,0);
        go(i, 0, 0, i);
    }

    cout << mn ; 

    return 0;
}