#include <bits/stdc++.h>    

using namespace std;


int N ; 
long long DP[91];
int main(){
    cin >> N;

    DP[0]=0;
    DP[1]=1;

    for(int i = 2 ; i <= N ; ++i){
        DP[i] = DP[i-1]+DP[i-2];
    }

    cout << DP[N];

    return 0;
}