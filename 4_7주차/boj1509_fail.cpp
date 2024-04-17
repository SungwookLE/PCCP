#include <bits/stdc++.h>
using namespace std;

string S;
bool DP[2505][2505]; // 시작과 끝에 대한 팰린드롬 문자열의 길이
int DP2[2505];
#define INF 987654321
vector<pair<int, int>> Combi;

bool go(pair<int, int> Q){
    if (Q.first >= Q.second){
        if (Q.first == Q.second) DP[Q.first][Q.second] = true;
        return true;
    }
    
    bool& ret = DP[Q.first][Q.second];
    if(ret) return ret;

    if (S[Q.first] == S[Q.second]){
        ret = go({Q.first+1, Q.second-1});
    }

    return ret;
}

int go2(int here){
    if(here >= S.size()) return 0; 

    int &ret = DP2[here]; 
    if(ret != INF) return ret;

    for(int i = here; i < S.size(); ++i){
        if (DP[here][i])
            ret = min(ret, go2(i+1)+1);
    }

    return ret; 
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> S;

    for(int i =0 ; i < S.size(); ++i){
        DP[i][i] = 1;
    }

    for(int i =0 ; i < S.size(); ++i){
        for(int j = i+1; j < S.size(); ++j){
            if (DP[i][j] == 0) go({i,j});
        }
    }

   
    fill(DP2, DP2+2505, INF);
    cout << go2(0);
  


    return 0;
}