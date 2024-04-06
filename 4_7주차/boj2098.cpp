#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> W;
vector<int> visited;
vector<vector<int>> DP;
int mn = 1E9;
#define INF 987654321
int cnt;

int tsp(int here, int visited){
    cout << cnt++ << ": "<<endl;

    if (visited == (1<<N)-1){ //  기저사례, 도시 전부 방문
        return W[here][0]? W[here][0]: INF;
    }

    cout << "CALL: " << here << " ";
    for(int i = 0 ; i < N ; ++i){
        if (visited & (1<<i)) cout << 1;
        else cout << 0;
    }
    cout << " " << DP[here][visited];
    cout << endl;

    int &ret = DP[here][visited]; // 메모이제이션, 이미 살펴본 정점에 대해선 또 살펴볼 필요가 없음
    if (ret != -1){
        return ret;
    } 


    cout << "RET : " << here <<" " ;
    for(int i = 0 ; i < N ; ++i){
        if (visited & (1<<i)) cout << 1;
        else cout << 0;
    }
    cout << " " << DP[here][visited];
    cout << endl;



    ret = INF;
    for(int i =0 ; i < N ; ++i){
        if (visited & (1<<i)) continue;
        if (W[here][i] == 0 ) continue;
        ret = min(ret, tsp(i, visited | (1<<i)) + W[here][i]); // 로직
    }

    return ret;

}


int main(){
    cin >> N;
    DP = vector<vector<int>>(N, vector<int>(1<<N,-1)); // 초기화
    visited = vector<int>(N,0);

    W = vector<vector<int>>(N, vector<int>(N,0));
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            cin >> W[i][j];
        }
    }

    cout << tsp(0, 1);

    return 0;
}