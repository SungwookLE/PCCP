#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> TH;
vector<vector<int>> DP;

int main(){

    cin >> N >> K;
    TH = vector<pair<int, int>>(N+1);
    DP = vector<vector<int>>(N+1, vector<int>(K+1, 0));

    for(int i =1 ; i <= N ; ++i){
        cin >> TH[i].first >> TH[i].second;
    }


    for(int j =1; j <=K ; ++j){

        for(int i = 1; i <= N; ++i){
           
            if (TH[i].first <= j){
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-TH[i].first] + TH[i].second);
            }
            else DP[i][j] = DP[i-1][j];
        }
        
    }

    cout << DP[N][K] ;


    return 0;
}