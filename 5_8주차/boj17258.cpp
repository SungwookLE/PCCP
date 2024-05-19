#include <bits/stdc++.h>

using namespace std;

int N, M, K, T;
vector<pair<int, int>> V;
int CNT[301];
int DP[301][301];

int go(int here, int num, int prev){

    if (here == V.size()) return 0;
    if (DP[here][num]) return DP[here][num];

    int cost = max(0, T-V[here].second);
    int real_cost = (prev >= cost) ? 0 : cost-prev;

    int& ret = DP[here][num];
    if (num - real_cost >= 0){
        return ret = max(go(here+1, num-real_cost, cost) + V[here].first, go(here+1, num,0));
    }
    else return ret = go(here+1, num,0);
}


int main(){
    cin >> N >> M >> K >> T;
    
    int a, b;
    for(int i =0 ; i < M ; ++i){
        cin >> a >> b;
        for(int i = a; i < b; ++i) CNT[i] = min(T, ++CNT[i]);
    }

    int temp = CNT[1];
    int _count = 1;

    for(int i = 2; i <= N ; ++i){
        if (temp != CNT[i]){

            V.push_back({_count, temp});
            _count = 0;
            temp = CNT[i];
        }
        _count ++;
    }
    V.push_back({_count, temp});

    cout << go(0,K,0);

    return 0;
}