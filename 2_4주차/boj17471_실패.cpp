#include <bits/stdc++.h>

using namespace std;

int N, ALL;
vector<int> people, visited, visited2;
vector<vector<int>> adj;
int mn = 100*200;

int go2(int n){
    int cnt = 1;
    if (visited[n] == 0 && visited2[n] == 0){
        visited2[n] = 1;
        for(int a : adj[n]){
            if (visited2[a] == 0){
                cnt += go2(a);
            }
        }
    }

    return cnt;
}


void go(int n, int sum , vector<int> ret){
    
    for(int i = 1 ; i <= N ; ++i){
        visited2 = visited;

        cout << go2(i) << endl;
        // if (go2(i)+ret.size()==N){
        //    if (mn > abs(ALL - sum - sum)) mn = abs(ALL - sum - sum);
        //    break;
        // }

    }

    for(auto a : adj[n]){
        if (visited[a] == 0){
            visited[a] = 1;
            ret.push_back(a);
            sum += people[a];
            go(a, sum, ret);
            ret.pop_back();
            sum -= people[a];
            visited[a] = 0;
        }
    }

    return;
}


int main(){

    cin >> N;
    people = vector<int>(N+1,0);
    visited = vector<int>(N+1,0);
    visited2 = vector<int>(N+1,0);

    adj = vector<vector<int>>(N+1, vector<int>());

    for(int i = 1 ; i <= N ; ++i) {
        cin >> people[i];
        ALL += people[i];
    }

    for(int i = 1 ; i <= N ; ++i){
        int n; cin >> n;
        for(int j = 0 ; j < n ; ++j){
            int a; cin >> a;
            adj[i].push_back(a);
            if (adj[i].empty()){
                cout << -1 ;
                return 0;
            }
        }
    }

    
    
    for(int i = 1; i <=N; ++i){
        visited[i] = 1;
        go(i, people[i], {i});
        visited[i] = 0;
    }

    cout << mn;

    return 0;
}