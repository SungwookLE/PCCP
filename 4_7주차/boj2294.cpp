#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> DP;
vector<int> C;
#define INIT 10000001

int main(){

    cin >> n >> k;
    C = vector<int>(n,0);
    DP = vector<int>(k+1,INIT);

    for(int i =0 ; i < n ; ++i){
        cin >> C[i];
        DP[C[i]] = 1;
    } 


    for(int i = 1 ; i <= k; ++i){

        if (DP[i] == INIT){
            int min_val = INIT+100;
            for(int c : C){
                if (i>c){
                    min_val = min(min_val, DP[i-c]);
                }
            }
            DP[i] = min_val+1;
        }
    }


    if (DP[k] >= INIT) cout << -1;
    else cout << DP[k];


}