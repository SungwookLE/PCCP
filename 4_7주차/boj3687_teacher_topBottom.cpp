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

string findMin(int here){
    // 탑바텀 DP
    if (here == 0) return "";
    string &ret = DP[here];
    
    if (ret != MAX_STR) return ret;
    for(int i = 0 ; i <= 9 ; ++i){
        if (here - A[i] <0) continue;
        if (here == N && i == 0) continue;

        ret = get_min_str(ret, to_string(i) + findMin(here-A[i]));
    }
    return ret;
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        fill(DP, DP+104, MAX_STR);
        cout << findMin(N) << " "<< findMax(N) << endl;
    }
}