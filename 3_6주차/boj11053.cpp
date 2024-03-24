#include <bits/stdc++.h>

using namespace std;


int N;
int A[1001], DP[1001];
int ret = 0;
int main(){

    cin >> N;
    for(int i =0 ; i < N ; ++i){
        cin >> A[i];
    }

    for(int i = 0; i < N ; ++i){

        int maxValue = 0;
        for(int j = 0; j<i ; ++j){

            if(A[i]>A[j]){
                if (maxValue < DP[j]) maxValue = DP[j];
            }
        }
        DP[i] = maxValue+1;
        if (ret < DP[i]) ret = DP[i];
    }

    cout << DP[N-1];


    return 0;
}