#include <bits/stdc++.h>

using namespace std;

int DP[10001];

int N;
int mx; 
vector<int>A;
int main(){

    cin >> N;
    A = vector<int>(N+1,0);
    for(int i =1 ; i <= N; ++i) cin >> A[i];

    DP[1] = A[1];
    DP[2] = A[1]+A[2];

    for(int i = 3; i <=N; ++i){
        DP[i] = max(max(DP[i-3]+A[i]+A[i-1] , DP[i-2]+A[i]), DP[i-1]);
    }


    cout << DP[N];




    return 0;
}