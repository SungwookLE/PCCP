#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<vector<int>> m, m_trans;
int ret;

void solve(vector<vector<int>> a){

    for(int i =0 ; i < N ; ++i){
        int cnt = 1;
        int j;
        for(j = 0; j < N-1; ++j){
            if (a[i][j] == a[i][j+1]) cnt ++; // 같은 값이면 카운트를 증가시켜나가다가
            else if (a[i][j] + 1 == a[i][j+1] && cnt>=L) cnt = 1;  // 높아지는 칸을 만나면, 카운트가 L보다 커야 패스
            else if (a[i][j] - 1 == a[i][j+1] && cnt>=0) cnt = -L+1; // 낮이지는 칸을 만나면, 
            else break;
        }
        if (j == N-1 && cnt>=0) ret++;
    }
    return;
}

int main(){

    cin >> N >> L;
    m = vector<vector<int>>(N, vector<int>(N,0));
    m_trans = vector<vector<int>>(N, vector<int>(N,0));

    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            cin >> m[i][j];
            m_trans[j][i] = m[i][j]; // 대칭배열
        }
    }

    solve(m); solve(m_trans);
    cout << ret;


    return 0;
}