#include <bits/stdc++.h>

using namespace std;

long long S, C;
vector<long long > A;
long long sum;


bool check(long long  mid){


    long long  ret =0 ;
    for(int i =0 ; i < S ; ++i){
        ret += (A[i] / mid);
    }

    if (ret >= C) return true;
    else return false;
}



int main(){
    cin >> S>> C;
    A = vector<long long >(S,0);

    for(int i =0 ; i < S ; ++i){ 
        cin >> A[i];
        sum += A[i];
    }
    // 파닭을 만들고 남은 파를 라면에 넣어먹으려 하는데, 파의 양을 구하라


    long long  left = 1;
    long long  right = 1E18;
    long long  ret = 0;
    while(left<=right){
        long long  mid = (left+right)/2;

        if (check(mid)){
            ret = mid;
            left = mid+1;

        }
        else{
            right = mid-1;

        }   
    }

    cout << sum - (long long)ret*(long long)C;


    return 0;
}