#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> DP;
int main(){
    cin >> N;
    DP = vector<int>(N+1, -1);


    DP[3] = 1;
    DP[4] = -1;
    DP[5] = 1;

    for(int i = 6 ; i <= N ; ++i){

        if (DP[i-3] != -1 && DP[i-5] != -1){
            DP[i] = min(DP[i-3], DP[i-5])+1;
        }
        else if (DP[i-3] != -1){
            DP[i] = DP[i-3]+1;
        }
        else if (DP[i-5] != -1){
            DP[i] = DP[i-5]+1;
        }

    }

    cout << DP[N];

    return 0;
}