#include <bits/stdc++.h>

using namespace std;

int N, ALL;
vector<int> people, visited;
vector<int> group;
vector<vector<int>> adj;
int mn = 100*200;

int go(int here, int id){
    visited[here] = 1;
    int ret = people[here];

    for(auto a : adj[here]){
        if (visited[a] == 0 && group[a] == id){
            ret+=go(a, id);
        }
    }

    return ret;
}


int main(){

    cin >> N;
    people = vector<int>(N+1,0);
    visited = vector<int>(N+1,0);
    group = vector<int>(N+1,0);


    adj = vector<vector<int>>(N+1, vector<int>());

    for(int i = 1 ; i <= N ; ++i){
        cin >> people[i]; ALL += people[i];
    }

    for(int i = 1 ; i <= N ; ++i){
        int n; cin >> n;
        for(int j = 0 ; j < n ; ++j){
            int a; cin >> a;
            adj[i].push_back(a);
        }
    }


    for(int i = 1; i < (1<<N) ; ++i){

        // 먼저 모두 쪼개고,
        for(int j = 0 ; j < N ; ++j){
            if (i & (1<<j)){
                group[j+1] = 1;
            }
            else group[j+1] = 0;
        }



        int cnt = 0;
        vector<int> ret;
        for(int j = 1; j <= N ; ++j){
            if (visited[j] == 0){
                ret.push_back(go(j, group[j]));
                cnt++;
            }
        }

        if (cnt == 2){
            if (mn > abs(ret[0]-ret[1])) mn = abs(ret[0]-ret[1]);
        }

        visited = vector<int>(N+1,0);

    }

    if (mn != 100*200)
        cout << mn;
    else cout << -1;


    
    return 0;
}