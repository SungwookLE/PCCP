#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> delta = {-1, 1, 2}; // 2 means multiply 2 times

vector<int> visited;
queue<int> candidates;

int mn = 100001;
vector<int> cnt;

int main(){
    cin >> N >> K;

    visited = vector<int>(1000001, 0);
    cnt = vector<int>(1000001, 0);


    candidates.push(N);
    visited[N] = 1;

    vector<int> ret = {1000001};

    while(!candidates.empty()){

        int now = candidates.front();
        candidates.pop();

        if (now == K){
            cnt[K]++;
            break;
        };

        int next_;
        for(auto d : delta){
            if (d!= 2) next_ = now+d;
            else next_ = now*2;

            if (next_ >= 0 && next_ < 3*K){
                if (visited[next_] == 0){
                    visited[next_] = visited[now]+1;
                    candidates.push(next_);
                }
                else if (visited[next_] >= visited[now] + 1){
                    cout << now << "->" << next_ << endl;
                    visited[next_] = visited[now]+1;
                    cnt[next_]+= 1;
                }


            }
        }
    }
    cout << visited[K]-1 << "\n";
    cout << cnt[K] ;


    return 0;
}