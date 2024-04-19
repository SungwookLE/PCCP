#include <bits/stdc++.h>
using namespace std;

string S;
bool DP[2505][2505]; // 시작과 끝에 대한 팰린드롬 문자열의 길이
int DP2[2505];
#define INF 987654321

void fill_palindrome_dp() {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        DP[i][i] = true;  
        if (i < n - 1 && S[i] == S[i + 1])
            DP[i][i + 1] = true;  
    }
 
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; 
            DP[i][j] = S[i] == S[j] && DP[i + 1][j - 1];
        }
    }
}

int go2(int here){
    if(here >= S.size()) return 0; 

    int &ret = DP2[here]; 
    if(ret != INF) return ret;

    for(int i = here; i < S.size(); ++i){
        if (DP[here][i]){
            ret = min(ret, go2(i+1)+1);
        }
    }

    return ret; 
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> S;
  
    fill_palindrome_dp();

    fill(DP2, DP2+2505, INF);
    cout << go2(0);

    return 0;
}