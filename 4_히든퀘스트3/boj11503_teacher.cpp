#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> LIS;
int mx;
int DP[1001];

int main(){
    cin >> N;
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i) cin >> A[i];


    for(int i = 0 ; i < N ; ++i){
        

        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
        if (it == LIS.end()) LIS.push_back(A[i]); // 가장 큰수니까 뒤에 넣어주고
        else (*it = A[i]); // 안에 들어온 값들은 바꿔주며 준비

    }

    cout << LIS.size(); 
    return 0;
}

/*
6
200 123 991 281 290 12

200 281 290
*/