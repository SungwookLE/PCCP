#include <bits/stdc++.h>

using namespace std;

int S;
int M, N;
vector<int> A, PsumA, B, PsumB;
map<int, int> aCnt, bCnt;
int ret;

void make(int n, vector<int>psum, map<int, int>& m){
    // 구간합 쿼리
    for(int interval = 1; interval <= n; ++interval){
        for(int start = interval; start <= n + interval -1; ++start){
            int sum = psum[start] - psum[start-interval];
            m[sum]++;
            if (interval == n) break;
        }
    }
}

int main(){
    cin >> S;
    cin >> M >> N;

    A = vector<int>(M,0);
    PsumA = vector<int>(2*M,0);

    B = vector<int>(N,0);
    PsumB = vector<int>(2*N,0);

    for(int i =0 ; i < M ; ++i) cin >> A[i];
    for(int i =0 ; i < M ; ++i) A.push_back(A[i]);

    PsumA[0] = A[0];
    for(int i =1 ; i < 2*M ; ++i) PsumA[i] = PsumA[i-1]+A[i];

    for(int i =0 ; i < N ; ++i) cin >> B[i];
    for(int i =0 ; i < N ; ++i) B.push_back(B[i]);

    PsumB[0] = B[0];
    for(int i =1 ; i < 2*N ; ++i) PsumB[i] = PsumB[i-1]+B[i];

    make(M, PsumA, aCnt);
    make(N, PsumB, bCnt);
    ret = (aCnt[S] + bCnt[S]);
    for(int i = 1; i < S; ++i){
        ret += (aCnt[i]*bCnt[S-i]);
    }
    cout << ret;


    return 0; 
}