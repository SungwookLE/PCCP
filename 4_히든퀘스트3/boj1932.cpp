#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<long long>> DP, A;
long long mx;

int main(){
    cin >> N;
    A = vector<vector<long long>>(N+1, vector<long long>(N+1,0));
    DP = vector<vector<long long>>(N+1, vector<long long>(N+1,0));


    for(int i = 1 ; i <= N ; ++i){
        for(int j = 1 ; j <=i;++j){
            cin >> A[i][j];
        }
    }

    DP[1][1] = A[1][1];

    for(int i =2 ; i <= N ; ++i){
        for(int j =1 ; j <= i ; ++j){
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + A[i][j];
        }
    }

    for(int j = 1 ; j <= N; ++j){
        mx = max(mx, DP[N][j]);
    }

    cout << mx ;

    return 0;
}