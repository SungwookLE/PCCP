#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> A;

int ans ;

// 아래 방식으로 시도해봄, 시간초과
/*
    void make_combi(int start, vector<int>ret){

        if(ret.size()==2){

            int sum = ret[0] + ret[1];
            if (sum == X) ans++;
            return;
        }


        for(int i = start+1; i < N; ++i){
            ret.push_back(A[i]);
            make_combi(i, ret);
            ret.pop_back();
        }
    }
*/

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    cin >> X;
    auto s = A.begin();
    auto e = A.end()-1;

    while ( s < e){
        if((*s+*e)==X){
            ans++;
            s++;
            e--;
        }
        else if ((*s+*e)>X) e--;
        else s++;
    }
    cout << ans;

    return 0;
}