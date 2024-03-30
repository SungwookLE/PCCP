#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> LIS, Ret;
int len;

vector<pair<int, int>> ans;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N ;
    A = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) cin >> A[i];

    for(int i = 0 ; i < N ; ++i){
        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
        ans.push_back({it-LIS.begin(), A[i]});

        if (it == LIS.end()) LIS.push_back(A[i]);
        else *it = A[i];

    }   


    int len = LIS.size();
    cout << len << endl;

    // 배열을 trace 
    for(int i = N-1 ; i >= 0 ; --i){
        if (ans[i].first == len-1){
            Ret.push_back(ans[i].second);
            len--;
        }
    }

    reverse(Ret.begin(), Ret.end());
    for(auto r: Ret) cout << r << " ";
    cout << endl;

    return 0;
}