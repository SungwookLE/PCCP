#include <bits/stdc++.h>

using namespace std;

string A, B;

int DP[1001][1001];

int main(){

    cin >> A >> B;


    for(int i =1 ; i <= A.size(); ++i){
        for(int j =1 ; j <= B.size(); ++j){

            if (A[i-1] == B[j-1]) DP[i][j] = DP[i-1][j-1]+1;
            else DP[i][j] =  max(DP[i][j-1], DP[i-1][j]);
        }
    }

    cout << DP[A.size()][B.size()];




    return 0;
}