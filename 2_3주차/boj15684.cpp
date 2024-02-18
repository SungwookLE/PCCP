#include <bits/stdc++.h>

using namespace std;

int N, M, H;
vector<vector<int>> visited; // ladder
int ret = 100; // max;

bool check(){
    for(int i = 1 ; i <= N ; ++i){
        int start =i;
        for(int j = 1 ; j <= H ; ++j){
            if (visited[j][start]) start++;
            else if (visited[j][start-1]) start--;
        }
        if (start != i) return false;
    }
    return true;
}

void go(int here, int cnt){

    if (cnt>3 || cnt >= ret ) return;
    if (check()){
        ret = min(ret, cnt); return;
    }

    for(int i = here; i <= H ; ++i){ // 높이를 증가하는 방향으로 이동시켜가며
        for(int j = 1; j < N; ++j){ // 너비를 이동시켜가며
            if (visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
            visited[i][j] = 1;
            go(i, cnt+1);
            visited[i][j] = 0;
        }
    }

    return ;
}

int main(){
    cin >> N >> M >> H;
    visited = vector<vector<int>>(H+1, vector<int>(N+1));

    int a, b;
    for(int i = 0 ; i < M ; ++i){
        cin >> a >> b;
        visited[a][b] = 1;
    }

    go(1, 0); // 높이 1에서 시작
    cout << ((ret==100) ? -1 : ret) << "\n";

    return 0;
}