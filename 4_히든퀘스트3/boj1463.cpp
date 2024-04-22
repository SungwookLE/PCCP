#include <bits/stdc++.h>

using namespace std;

int N;
#define INF 987654321
int DP[1000001];

int go(int n){


    if(n==1){
        return 0;
    }
    else if (n<1){
        return INF;
    }

    int& ret = DP[n];
    if(ret != INF) return ret;

    if(n%3==0) ret = min(ret, go(n/3)+1);
    if(n%2==0) ret = min(ret, go(n/2)+1);
    ret = min(ret, go(n-1)+1);

    return ret;
}

int main(){
    cin >> N;

    fill(DP, DP+1000001, INF);
    cout << go(N);




    return 0;
}