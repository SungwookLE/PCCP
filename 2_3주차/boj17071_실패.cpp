#include <bits/stdc++.h>

using namespace std;

queue<int> candidates;
vector<int> delta = {-1, 1, 2};
vector<int> visited, sister;

int N, K;

int main()
{
    cin >> N >> K;

    visited = vector<int>(5000001, 0);
    sister = vector<int>(5000001, 0);


    vector<int> preSum(500001, 0);
    preSum[0] = K;
    sister[K] = 1;
    
    for(int i = 1 ; i <= 500000; ++i){
        preSum[i] = preSum[i-1] + i;
        if (preSum[i] >= 500000) break;

        int new_K = preSum[i];
        sister[new_K] = i+1;

    }


    candidates.push(N);
    visited[N] = 1;

    while(!candidates.empty()){

        int now = candidates.front();

        if (visited[now] <= sister[now] && (sister[now] - visited[now])%2 == 0){
            cout<< sister[now]-1 << endl;
            break;
        } 
        candidates.pop();


        for(int d : delta){
            int next_;
            
            if (d!=2) next_ = now+d;
            else next_ = now*2;

            if (next_ >= 0 && next_ < 500001){

                if(visited[next_] == 0){
                    candidates.push(next_);
                    visited[next_] = visited[now]+1;
                }
            }

        }
    }
    if (candidates.empty()) cout << -1 << endl;


    return 0;
}