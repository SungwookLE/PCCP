#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
int DP[100001];
int mx = -2000;

int main(){

    cin >> N;
    A = vector<int>(N+1,0);

    DP[0] = 0;
    for(int i = 1 ; i <= N ; ++i){
        cin >> A[i];
        DP[i] = max(DP[i-1] + A[i], A[i]);
        mx = max(mx, DP[i]);

    }

    cout << mx;

    return 0;
}