#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, LIS, Ans;
vector<pair<int, int>> Carry;
int main(){
    cin >> N ;
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> A[i];

    for(int i =0 ; i < N; ++i){
        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
        Carry.push_back({it-LIS.begin(), A[i]});

        if (it == LIS.end()) LIS.push_back(A[i]);
        else *it = A[i];
    }

    cout << LIS.size() << endl;

    int len = LIS.size();
    reverse(Carry.begin(), Carry.end());

    for(auto r : Carry){
        if (r.first + 1 == len){
            Ans.push_back(r.second);
            len--;
        }
    }

    reverse(Ans.begin(), Ans.end());
    for(auto a : Ans) cout << a << " ";

    return 0;

}