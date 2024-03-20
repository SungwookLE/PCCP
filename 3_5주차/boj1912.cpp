#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;
int sum;
int mx = -200000000;

// int query(){
// 시간초과
//     for(int interval = 1; interval <= n ; ++interval){

//         if (mx < psum[interval-1]) mx = psum[interval-1];
//         for(int i = 0; i < n-interval; ++i ){
//             int ret = psum[i+interval]-psum[i];
//             if (mx < ret) mx = ret;
//         }

//     }

//     return mx;
// } 

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    A = vector<int>(n,0);

    for(int i =0 ; i < n ; ++i){
        cin >> A[i];

        sum += A[i];
        if (mx < sum) mx = sum; // 매번 mx 체크
        if (sum <0) sum = 0; // 다음 구간 진행
    } 

    cout << mx;

    return 0;
}