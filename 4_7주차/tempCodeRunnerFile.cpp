#include <bits/stdc++.h>

using namespace std;

int N, K;
typedef struct{
    int TIME_TOWALK;
    int GET_TOWALK;
    int TIME_TORIDE;
    int GET_TORIDE;
} st;
vector<st> W;
int DP[101][100001];

int go(int idx, int Reward, int TIME){

    int ret = 0;
    if (idx == N){
        if (TIME <= K) return Reward;
        else return 0;
    }


    // int& ret = DP[idx][TIME];
    // if(ret) return ret;

    // cout << idx << " "  << TIME << endl;
    if (TIME +W[idx].TIME_TOWALK  <= K) ret = max(ret, go(idx+1, Reward + W[idx].GET_TOWALK, TIME + W[idx].TIME_TOWALK));
    if (TIME +W[idx].TIME_TORIDE  <= K) ret = max(ret, go(idx+1, Reward + W[idx].GET_TORIDE, TIME + W[idx].TIME_TORIDE));

    return ret;
}


int main(){

    cin >> N >> K;
    W = vector<st>(N);
    for(int i = 0 ; i < N; ++i){
        cin >> W[i].TIME_TOWALK >> W[i].GET_TOWALK >> W[i].TIME_TORIDE >> W[i].GET_TORIDE;
    }


    // K분 이내로 여행하면서 모금할 수 있는 최대 금액
    cout << go(0, 0, 0); 


    return 0;
}