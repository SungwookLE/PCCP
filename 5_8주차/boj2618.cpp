// 처리해야할 사건들이 순서대로 주어질 때, 두 대의 경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램

#include <bits/stdc++.h>
using namespace std;

int N, W;
vector<pair<int, int>> E;
int DP[1003][1003];

int dist(int a,  int b){
    return abs( E[a].first - E[b].first ) + abs( E[a].second - E[b].second );
}

int getSum(int a, int b){
    if (a == W+1 || b == W+1) return 0;

    int &ret = DP[a][b];
    if(ret) return ret;

    int next = max(a,b)+1;
    ret = min(getSum(a, next)+dist(b, next), getSum(next, b)+dist(a, next));

    return ret;
}

void solve(){
    int a = 0, b = 1;
    for(int i = 2 ; i < W+2; ++i){

        if (DP[i][b] + dist(a, i) < DP[a][i] + dist(b,i)) cout << "1\n", a = i;
        else cout << "2\n", b = i;

    }
    return;
}

int main(){

    cin >> N >> W;
    E = vector<pair<int, int>>(W+2);

    // 경찰차 한대는 (1,1) 위치에 있고, 경찰차 한대는 (N, N) 위치에 있다.
    pair<int, int> A = {1,1};
    pair<int, int> B = {N, N};
    E[0] = A;
    E[1] = B;

    for(int i =2 ; i < W+2 ; ++i){
        cin >> E[i].first >> E[i].second;
    }


    cout << getSum(0, 1) <<"\n";
    solve();


    return 0;
}


