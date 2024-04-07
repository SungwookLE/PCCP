#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> DP;

void trace(int here){
    cout << here << " ";
    if(here%3==0 && DP[here] == DP[here/3]+1){
        trace(here/3);
    }
    else if (here%2==0 && DP[here] == DP[here/2]+1){
        trace(here/2);
    }
    else if (DP[here] == DP[here-1]+1){
        trace(here-1);
    }
    return;
}


int main(){

    cin >> N;
    DP = vector<int>(N+10);

    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;    

    for(int i = 4 ; i <= N; ++i){

        if (i%3==0 && i%2==0){
            int idx = 0;
            int val = min(min(DP[i/3], DP[i/2]), DP[i-1]);
            if (val == DP[i/3]) idx = i/3;
            else if (val == DP[i/2]) idx = i/2;
            else idx = i-1;
            DP[i] = DP[idx]+1;
        }
        else if (i%3==0){
            int idx = 0;
            if (DP[i/3] < DP[i-1]) idx = i/3;
            else idx = i-1;
            DP[i] = DP[idx]+1;
        }
        else if (i%2==0){
            int idx = 0;
            if (DP[i/2] < DP[i-1]) idx = i/2;
            else idx = i-1;
            DP[i] = DP[idx]+1;
        }
        else{
            DP[i] = DP[i-1]+1;
        }
    }

    int ret = DP[N];
    cout << ret << "\n";

    trace(N);

    return 0;
}