#include <bits/stdc++.h>

using namespace std;


int N;
vector<pair<int, int>> T;
vector<int> LIS(501,0);

int len;
int ret;

int main(){
    cin >> N ;
    T = vector<pair<int, int>>(N);

    for(int i =0 ; i < N; ++i){
        cin >> T[i].first >> T[i].second;
    }

    // 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하라
        // 1. 먼저. X축 기준으로 오름차순 정렬하고
        // 2. Y축 기준의 LIS를 구하면, 그것이 얻을 수 있는 꼬이지 않는 전깃줄의 최대값임

    sort(T.begin(), T.end());

    for(int i =0 ; i < N ; ++i){

        auto it = lower_bound(LIS.begin(), LIS.begin()+len, T[i].second);
        if (*it == 0) len++;
        *it = T[i].second;

    }
    cout << N-len;


    return 0;
}