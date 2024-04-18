#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int RIGHT;
vector<int> S;
ll DP[105][25]; // DP[idx][val]

ll dfs(int idx, int res){

    if (res < 0 || res > 20) return 0;

    if (idx == N-1){
        if (res == RIGHT) return 1;
        else return 0;
    }

    ll& ret = DP[idx][res];
    if (ret) return ret;
    

    ret += dfs(idx+1, res + S[idx]);
    if (idx != 0)
    ret += dfs(idx+1, res - S[idx]);

    return ret;
}



int main(){
    cin >> N;
    S = vector<int>(N-1,0);

    for(int i =0 ; i < N-1 ; ++i) cin >> S[i];
    cin >> RIGHT;

    cout << dfs(0, 0);

    return 0;
}