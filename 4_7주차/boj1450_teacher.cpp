#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> W;
vector<int> v, v2;
int ret;

void go(int here, int _n, vector<int>&v, int sum){

    if (sum > C) return;
    if (here == _n){
        v.push_back(sum); return;
    }

    go(here+1, _n, v, sum + W[here]);
    go(here+1, _n, v, sum);

    return;
}



int main(){
    cin >> N >> C;

    W = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i){
        cin >> W[i] ;
    }

    go(0, N/2, v, 0);
    go(N/2, N, v2, 0);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    for(int b : v){
        if (C-b >= 0) ret += upper_bound(v2.begin(), v2.end(), C-b) - v2.begin();
    }

    cout << ret;

    return 0;
}