#include <bits/stdc++.h>

using namespace std;

int N;
int DP[1000010];
map<string, int> mp;

int go(int n, string res){
// 완탐
    int ret = 0;

    if (n<=0){
        if (n==0){
            mp[res]+=1;
            return 1;
        }
        return 0;
    }


    ret+=go(n-2, res+"11");
    ret+=go(n-2, res+"00");
    ret+=go(n-1, res+"1");
    
    return ret;
}


int main(){
    cin >> N;

    // 가지고 있는 타일은 '1', '00'
    // 만들 수 있는 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지
    DP[1] = 1;
    DP[2] = 2;

    for(int i = 3 ; i <= N; ++i){
        DP[i] = (DP[i-1]+DP[i-2])%15746;
    }

    cout << DP[N] << endl;

    return 0;
}