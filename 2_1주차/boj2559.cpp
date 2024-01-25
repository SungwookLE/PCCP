#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;


    vector<int> arr(N,0);
    for(int i = 0 ; i < N ; ++i){
        cin >> arr[i];
    }

    vector<int> DP(N+1, 0);

    for(int i = 1 ; i <= K ; ++i)
        DP[K] += arr[i-1];

    int answer = DP[K];
    for(int i = K+1 ; i <= N ; ++i){
        DP[i] = DP[i-1] + arr[i-1] - arr[i-1-K];

        if (DP[i] > answer)
            answer = DP[i];
    }


    cout << answer << "\n";

    return 0;
}


void usingPsum(){
    int N, K;
    cin >> N >> K;

    vector<int> psum(N+1, 0);
    int answer = -10000004;

    int temp;
    for(int i = 1 ; i <= N ; ++i){
        cin >> temp; 
        psum[i] = psum[i-1] + temp;
    }


    for(int i = K ; i <= N; ++i){
        answer = max(answer, psum[i] - psum[i-K]);
    }

    cout << answer << endl;
}