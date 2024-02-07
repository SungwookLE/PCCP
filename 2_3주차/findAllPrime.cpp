#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

bool check(int n){ // 소수판별
    if (n<= 1) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    for(int i = 2; i * i <= n ; ++i){
        if(n%i == 0) return 0;
    }
    return 1;
}


int go(int idx,int sum){
    if (idx == N){
        return check(sum);
    }

    return go(idx+1, sum + v[idx]) + go(idx+1, sum);
}

// 문제 설명: 주어진 숫자 배열이 있을떄, 조합의 합이 소수인 것의 총 경우의 수는?
int main(){
    cin >> N;
    v = vector<int>(N,0);
    for(int i = 0 ; i < N; ++i)
        cin >> v[i];

    int ret = go(0, 0);
    cout << ret << endl;

    return 0;
}