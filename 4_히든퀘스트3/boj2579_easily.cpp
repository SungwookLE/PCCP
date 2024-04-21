#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> sum;



int main(){
    cin >> N;
    A = vector<int>(N+1,0);
    sum = vector<int>(N+1,0);


    for(int i = 1; i<=N; ++i) cin >> A[i];

    sum[1] = A[1];
    sum[2] = A[1] + A[2];
    sum[3] = max(A[1]+A[3], A[2]+A[3]);

    for(int i = 4; i <= N; ++i){
        sum[i] = max(sum[i-2]+A[i], sum[i-3]+A[i-1]+A[i]);
    }

    return 0;
}