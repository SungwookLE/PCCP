#include <bits/stdc++.h>

using namespace std;

int N, K;
const int max_n = 500000;
queue<int> candidates;
vector<vector<int>> visited;
int ok, turn=1;

int main(){

    cin >> N >> K;
    visited = vector<vector<int>>(2, vector<int>(max_n+4,0));

    if ( N == K ){
        cout << 0 <<  "\n";
        return 0;
    } 

    candidates.push(N);
    visited[0][N] = 1;

    while(!candidates.empty()){
        K += turn;                              // 이렇게 동생의 위치를 업데이트 해주고 있기 때문에
        if (K>max_n) break;

        if (visited[turn%2][K]){
            ok = true;
            break;
        }

        int qSize = candidates.size();
   //  bfs 내부에 아래와 같이 fluid fill 방식으로 단계에 맞는 candidate가 queue에 들어오도록 해주어야 한다.
        for(int i =0 ; i < qSize; ++i){        
            int now = candidates.front(); candidates.pop();
            for(int next_ : {now-1, now+1, now*2}){
                if (next_ >= 0 && next_ <= max_n){
                    if (visited[turn%2][next_] == 0){
                        visited[turn%2][next_] = visited[(turn+1)%2][now]+1;

                        if (next_ == K){
                            ok = true;
                            break;
                        }
                        candidates.push(next_);
                    }
                }
            }
            if(ok) break;
        }
        if(ok) break;


        turn ++;
    }

    if(ok) cout << turn <<"\n";
    else cout << -1 << "\n";
    return 0;
}