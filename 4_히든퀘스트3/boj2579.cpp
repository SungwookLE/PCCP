#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int DP[3][305];

int main(){
    cin >> N;
    A = vector<int>(N+1,0);

    for(int i =1 ; i <= N ; ++i) cin >> A[i];

    DP[1][1] = A[1];
    DP[2][1] = 0;

    for(int i = 2 ; i <= N; ++i){
        DP[1][i] = max(DP[1][i-2], DP[2][i-2])+A[i];
        DP[2][i] = DP[1][i-1]+A[i];
    }

    cout << max(DP[1][N], DP[2][N]);

    return 0;
}