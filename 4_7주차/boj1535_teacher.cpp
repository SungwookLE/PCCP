#include <bits/stdc++.h>
using namespace std;
int n, DP[101], cost[101], happy[101];

int main(){

    cin >> n;
    for(int i =0; i < n ; ++i) cin >> cost[i];
    for(int i =0; i < n ; ++i) cin >> happy[i];
    
    for(int i =0 ; i < n ; ++i){
        for(int j = 100; j > cost[i]; j--){

            DP[j] = max(DP[j] , DP[j-cost[i]] + happy[i]);
        }
    }

    cout << DP[100];

    return 0;
}