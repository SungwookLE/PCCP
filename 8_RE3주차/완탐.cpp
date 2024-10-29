#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> G;

int check(int sum){
    if (sum<=1) return 0;
    if (sum==2) return 1;
    for(int i = 2; i*i <= sum; ++i){
        if (sum%i ==0) return 0;
    }
    return 1;
}

int go(int idx, int sum){
    if (idx == N){
        return sum%11;
    }
    int include = go(idx+1, sum+G[idx]);
    int exclude = go(idx+1, sum);
    return max(include, exclude);
}

int main(){
    cin >> N ;
    G.resize(N,0);
    for(int i = 0; i < N ; ++i){
        cin >> G[i];
    }

    cout << go(0, 0);

    return 0;
}