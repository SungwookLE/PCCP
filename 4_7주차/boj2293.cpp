#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;
vector<int> DP;


int main(){

    cin >> n >> k;
    A = vector<int>(n,0);
    DP = vector<int>(k+1,0);
    DP[0] = 1;

    for(int i =0 ; i < n; ++i) cin >> A[i];

    for(int a : A){
        for(int i = 1; i <= k ; ++i){
            if (i >= a){
                DP[i] += DP[i-a];
            }                
        }
    }

    cout << DP[k] ;


    return 0;
}