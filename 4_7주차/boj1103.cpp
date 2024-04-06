#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> B;
int DP[52][52];
int CHECK[52][52];
#define INF 987654321

vector<vector<int>> delta = {{-1,0},{1,0},{0,-1}, {0,1}};

int go(pair<int, int> here){

    if (here.first < 1 || here.first > N) return 0; // 기저사례
    if (here.second < 1 || here.second > M) return 0; // 기저사례
    if (B[here.first][here.second] == 'H') return 0; // 기저사례

    if(CHECK[here.first][here.second] == 1){ // 기저사례: 이미 갔던 곳인데 또 갈 수 있다는 뜻은 무한히 갈 수 있다는 뜻
        return INF;
    }

    int& ret = DP[here.first][here.second];     // 메모이제이션
    if(ret) return ret;

    CHECK[here.first][here.second] =1 ; // 갔던 곳 체크
    for(int i = 0 ; i < 4; ++i){
        int value = B[here.first][here.second]-'0';
        int next_i = here.first  + value*delta[i][0];
        int next_j = here.second + value*delta[i][1];
        ret = max(ret, go({next_i, next_j})+1); // 로직
    }
    CHECK[here.first][here.second] =0 ; // 원복

    return ret;
}

int main(){
    cin >> N >> M;
    B = vector<vector<char>>(N+1, vector<char>(M+1));

    string s;
    for(int i = 1 ; i <= N ; ++i){
        cin >> s;
        for(int j =0 ; j < M ; ++j){
            B[i][j+1]=s[j];
        }
    }

    int ret = go({1,1});
    if (ret>= INF) cout << -1;
    else cout << ret;

    return 0;
}