#include <bits/stdc++.h>

using namespace std;
vector<int> adj[25];
int searched[25];
queue<int> candidates;

void bfs(int start){

    searched[start] =1;
    candidates.push(start);

    while(candidates.size()){

        int here = candidates.front();
        cout << here << endl;
        candidates.pop();

        for(auto there: adj[here]){
            if (searched[there] == 0){

                candidates.push(there);
                searched[there] = searched[here]+1;
            }
        }
    }

    return;
}

int main(){

    adj[10].push_back(12);
    adj[10].push_back(14);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);

    // 최단거리 정보 출력
    for(int i = 0 ; i < 25; ++i){
        cout << i << ": " << searched[i]-1 << "\n";
    }

    return 0;
}