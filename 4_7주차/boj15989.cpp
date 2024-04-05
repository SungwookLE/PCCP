#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> n;
int mx = 0;
vector<int> DP;
int main(){

    cin >> T;
    n = vector<int>(T,0);

    for(int i = 0; i < T; ++i){
        cin >> n[i];
        if (mx < n[i]) mx = n[i];
    }

    DP = vector<int>(mx+1,0);
    DP[0] = 1;

    for(int i = 1; i <= 3; ++i){
        for(int j = 1 ; j <= mx; ++j){
            if (j >= i){
                DP[j] += DP[j-i]; 
            }
        }
    }

    for(int i =0  ; i < T  ; ++i){
        cout << DP[n[i]] << endl;
    }






    return 0;
}