#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<vector<int>> DP;
vector<int> ans;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N ;
    A = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) cin >> A[i];
    DP = vector<vector<int>>(N);
    DP[0].push_back(A[0]);

    for(int i =0 ; i < N; ++i){
        int len = 0;
        for(int j = i-1; j >= 0 ; --j){
            if (A[i] > A[j])
                if ( DP[j].size() > len){

                    len = DP[j].size();
                    DP[i] = DP[j];
                    DP[i].push_back(A[i]);

                    if (ans.size() < DP[i].size()) ans = DP[i];
                }
        }
    }

    for(auto a : ans) cout << a << " ";



    return 0;
}