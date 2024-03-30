#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, LIS;

int main(){
    cin >> N;   
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> A[i];

    // 시간복잡도: O(NlogN)
    for(int i =0 ; i < N ; ++i){

        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
        if( it == LIS.end()) LIS.push_back(A[i]);
        else *it = A[i];
    }

    cout << LIS.size(); 




    return 0;


}