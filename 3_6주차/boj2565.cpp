#include <bits/stdc++.h>

using namespace std;


int N;
vector<pair<int, int>> T;
vector<int> DP;

int len;
int ret;

int main(){
    cin >> N ;
    T = vector<pair<int, int>>(N);
    DP = vector<int>(N,1);

    for(int i =0 ; i < N; ++i){
        cin >> T[i].first >> T[i].second;
    }

    // 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하라
    sort(T.begin(), T.end());

    for(int i =0 ; i < N ; ++i){


        for(int j =0 ; j < i ; ++j){

            if (T[i].first > T[j].first && T[i].second > T[j].second){
                DP[i] = max(DP[i], DP[j]+1);

                if (ret < DP[i]) ret = DP[i];
            }

        }
    }

    cout << N-ret;


    return 0;
}