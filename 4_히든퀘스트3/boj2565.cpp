#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> Q;
vector<int> LIS;

int main(){
    cin >> N ;
    Q = vector<vector<int>>(N, vector<int>(2,0));


    for(int i = 0; i < N ; ++i){
        cin >> Q[i][0] >> Q[i][1];
    }

    // LIS 구하기
    sort(Q.begin(), Q.end(), [](auto a, auto b){
        if (a[0]<b[0]) return true;
        else if (a[0]==b[0]) return a[1] < b[1];
        else return false;
    });

    for(int i =0 ; i < N ; ++i){
        auto it = lower_bound(LIS.begin(), LIS.end(), Q[i][1]);
        if (it == LIS.end()){
            LIS.push_back(Q[i][1]);
        }
        else{
            *it = Q[i][1];
        }

    }

    cout << Q.size() - LIS.size() ;


    return 0;
}