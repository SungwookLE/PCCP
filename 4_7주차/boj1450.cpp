#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> W;
long long DP[35][3];

long long go(int idx, long long res, int in){

    if (idx == N){
        if (res <= C) return 1;
        else return 0;
    }

    long long& ret = DP[idx][in];
    if(ret) return ret;

    ret+=go(idx+1, res, in);
    ret+=go(idx+1, res + W[idx], 1^in);

    return ret;
}

int main(){
    cin >> N >> C;

    W = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i){
        cin >> W[i] ;
    }

    cout << go(0, 0, 0) << "\n";
    

    return 0;
}