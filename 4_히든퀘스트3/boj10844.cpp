#include <bits/stdc++.h>

using namespace std;

int N;
long long DP[101][10];

long long go(int n, int cur){

    if(n==1){
        return 1;
    }

    long long& ret = DP[n][cur];
    if(ret) return ret;
    
    if(cur == 0){
        ret+=(go(n-1, 1))%1000000000;
    }
    else if(cur==9){
        ret+=(go(n-1, 8))%1000000000;
    }
    else{
        ret+=(go(n-1,cur-1))%1000000000;
        ret+=(go(n-1,cur+1))%1000000000;
    }

    ret %= 1000000000;

    return ret;

}



int main(){
    cin >> N;

    long long ret = 0;
    for(int i = 1; i <=9; ++i){
        ret += go(N, i);
    }
    cout << ret%1000000000;

    return 0;
}