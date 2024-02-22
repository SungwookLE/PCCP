#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> people, visited, visited2;
vector<vector<int>> graph;
int all;
int ans_mn = 10*200;

void dfs2(int here){
    // cout << here << " ";
    visited2[here] = 1;

    for(auto v : graph[here]){
        if (visited2[v] == 0)
            dfs2(v);
    }
}

void dfs(int here, int sum, vector<int> ret){
    
    cout << here << " " ;

    for(auto v: graph[here]){
        if (visited[v] == 0){
            visited[v] =1 ;
            sum += people[v];
            ret.push_back(here);
            dfs(v, sum, ret);
            visited[v] -=1 ;
        } 
    }

    return;
}


int main(){

    cin >> N;
    people = vector<int>(N+1,0);
    visited = vector<int>(N+1,0);
    visited2 = vector<int>(N+1,0);


    for(int i = 1 ; i <= N ; ++i){
        cin >> people[i];
        all += people[i];
    }

    graph = vector<vector<int>>(N+1);

    int n_adj;
    for(int i = 1; i <= N ; ++i){
        cin >> n_adj;

        for(int j = 0 ; j < n_adj; ++j){
            int n; cin >> n;
            graph[i].push_back(n);
        }
    }

    for(int i = 1 ; i <= N ; ++i)
        dfs(i, 0, {});


    return 0;
}