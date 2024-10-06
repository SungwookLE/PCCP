#include <bits/stdc++.h>
using namespace std;


int N, K;
int TEMP[100001];
int PSUM[100001];

int main(){
    cin >> N >> K;

    for(int i =1 ; i <= N ; ++i){
        cin >> TEMP[i];
    }

    for(int i = 1; i <=N; ++i){
        PSUM[i] = TEMP[i] + PSUM[i-1];
    }

    int mx = -20000000;
    for(int i = K; i <= N ; ++i){

        int query = PSUM[i]-PSUM[i-K];
        if (query > mx){
            mx = query;
        }

    }

    cout << mx ;

    


    return 0;
}