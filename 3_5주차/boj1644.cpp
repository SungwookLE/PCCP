#include <bits/stdc++.h>

using namespace std;

int N;

bool check_prime(int n){

    if (n==1) return false;
    else if (n==2) return true;
    else {
        for(int div = 2; div * div <= n ; ++div){
            if (n%div ==0) return false;
        }
        return true;
    }
}


int main(){

    cin >> N;

    vector<int> P;
    int cnt = 0;
    for(int i = 2; i<= N; ++i){
        if (check_prime(i)){
            P.push_back(i);

            int ret =0 ;
            for(int j = P.size()-1; j >=0; --j){
                ret += P[j];
                if (ret == N) cnt += 1;
                else if (ret>N) break; // 조기종료 조건 추가해주니 시간초과 통과 휴..
            }
        }
    }

    cout << cnt;

    return 0;
}