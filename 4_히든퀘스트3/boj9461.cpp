#include <bits/stdc++.h>

using namespace std;


int T, N;
long long DP[122];


int main(){
    cin >> T;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for(int i = 4; i<= 121; ++i){
        DP[i] = DP[i-2]+DP[i-3];
    }


    for(int i = 0; i < T; ++i){
        cin >> N;
        cout << DP[N] <<"\n";
    }




    return 0;

}