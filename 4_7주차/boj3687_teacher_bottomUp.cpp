#include <bits/stdc++.h>

using namespace std;

int A[10] = {6,2,5,5,4,5,6,3,7,6}, T, N;
string DP[104], MAX_STR = "11111111111111111111111111111111111111111111111111111";

string get_min_str(string a, string b){
    if (a.size() == b.size()) return (a<b? a:b);
    if (a.size() < b.size()) return a;
    else return b;
}

string findMax(int here){
    // 그리디 
    string ret = "";
    if (here&1){ret += '7'; here -= 3;} // 홀수라면
    while(here){
        ret += '1';
        here -=2;
    }
    return ret;
}


int main(){
    cin >> T;


    // 바텀업 DP
    fill(DP, DP+104, MAX_STR);
    DP[0] = "";
    for(int i = 2; i <104 ; ++i){
        for(int j = 0 ; j <= 9 ; ++j){
            if(i-A[j] < 0) continue;
            if (j==0 && DP[i-A[j]] == "") continue;
            DP[i] = get_min_str(DP[i], DP[i-A[j]] + to_string(j));
        }
    }

    while(T--){
        cin >> N;
        cout << DP[N] << " "<< findMax(N) << endl;
    }
}