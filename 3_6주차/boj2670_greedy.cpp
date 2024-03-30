#include <bits/stdc++.h>

using namespace std;

int N;
vector<double>A;
vector<double>pMul;
double mx = 0.0;
int main(){
    cin >> N;
    A = vector<double>(N);
    pMul = vector<double>(N);

    for(int i =0 ; i < N ; ++i){
        cin >> A[i];
    }
    // 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하시오.
    mx = A[0];
    pMul[0] = A[0];
    for(int i =1 ; i < N; ++i){

        if (pMul[i-1]*A[i] < A[i]) pMul[i] = A[i];
        else pMul[i] = pMul[i-1]*A[i];

        mx = max(pMul[i],mx);
    }


    cout << fixed;
    cout.precision(3);
    
    cout <<  mx ;





    return 0;
}