#include <bits/stdc++.h>

using namespace std;

int N;
int K;
vector<pair<int, int>> T;
int DP[101][100001];

int main(){

    cin >> N >> K;
    T = vector<pair<int, int>>(N+1);
    for(int i =1 ; i <= N; ++i){
        cin >> T[i].first >> T[i].second;
    }

    
    for(int i = 1 ; i <= N ; ++i){

        for(int k = 1; k <= K ; ++k){
            if (T[i].first<=k){
                DP[i][k] = max(DP[i-1][k-T[i].first]+T[i].second, DP[i-1][k]);
            }
            else{
                DP[i][k] = DP[i-1][k];
            }
        }
    }

    cout << DP[N][K];

    return 0;
}