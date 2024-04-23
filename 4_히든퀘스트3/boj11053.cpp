#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
int DP[2001];
int mx = 1;

int main(){
    cin >> N;
    A = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) cin >> A[i];

    
    DP[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        DP[i] = 1;
        for(int j = i-1; j >= 0 ; --j){
            if (A[i] > A[j]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        mx = max(mx, DP[i]);
    }

    cout << mx;

    return 0;
}