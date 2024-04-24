#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int DP_LEFT[1001], DP_RIGHT[1001];
int mx;

int main(){
    cin >> N;
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> A[i];

    DP_LEFT[0] = 1;
    for(int i =1 ; i < N ; ++i){
        DP_LEFT[i] = 1;
        for(int j = i-1 ; j >= 0 ; --j){
            if (A[i] > A[j]){
                DP_LEFT[i] = max(DP_LEFT[i], DP_LEFT[j]+1); 
            }
        }
    }

    DP_RIGHT[N-1] = 1;
    for(int i =N-2 ; i >= 0 ; --i){
        DP_RIGHT[i] = 1;
        for(int j = i+1 ; j < N; ++j){
            if (A[i] > A[j]){
                DP_RIGHT[i] = max(DP_RIGHT[i], DP_RIGHT[j]+1);
            }
        }
    }

    mx = max(DP_LEFT[N-1], DP_RIGHT[0]);
    for(int i = 0; i < N-1; ++i){
        for (int j = i+1; j < N; ++j)
            if (A[i] != A[j]) mx = max(mx, DP_LEFT[i] + DP_RIGHT[j]);
    }

    cout << mx;


 
    return 0;
}