#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> C;
#define INF 987654321
int DP[1005][4];

int go(int idx, int curColor){

    if(idx == N){
        return 0;        
    }

    int& ret = DP[idx][curColor];
    if(ret != INF) return ret;

    if(curColor == 0){
        ret = min(ret, go(idx+1, 1) + C[idx][1]);
        ret = min(ret, go(idx+1, 2) + C[idx][2]);
    }
    else if (curColor == 1){
        ret = min(ret, go(idx+1, 0) + C[idx][0]);
        ret = min(ret, go(idx+1, 2) + C[idx][2]);
    }
    else{
        ret = min(ret, go(idx+1, 0) + C[idx][0]);
        ret = min(ret, go(idx+1, 1) + C[idx][1]);
    }

    return ret;
}


int main(){

    cin >> N;
    C = vector<vector<int>>(N, vector<int>(3,0));

    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < 3 ; ++j){
            cin >> C[i][j];
        }
    }
    fill(&DP[0][0], &DP[0][0]+sizeof(DP)/sizeof(int), INF);

    cout << min(min(go(0, 0), go(0, 1)), go(0,2));







    return 0;
}