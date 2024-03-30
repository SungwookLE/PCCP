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

    pMul[0] = A[0];
    for(int i =1 ; i < N ; ++i){
        if (pMul[i-1] == 0) pMul[i] = A[i];
        else pMul[i] = pMul[i-1]*A[i];
    }

    for(int i =0 ; i < N; ++i){
        
        double temp = pMul[i];
        for(int j = i-1 ; j >= 0 ; --j){
            if (pMul[j] == 0) break;
            if (temp < pMul[i]/pMul[j]) temp = pMul[i]/pMul[j];
        }

        if (temp > mx) mx = temp;
    }


    cout << fixed;
    cout.precision(3);
    
    cout <<  mx ;





    return 0;
}