

#include <bits/stdc++.h>

using namespace std;


bool adj[10][10];
bool visited[10];

void dfs(int from){
    visited[from] = 1;
    cout << from << endl;
    for(int j = 0 ; j < 10 ; ++j){
        if(adj[from][j] == 1){
            if (visited[j] == 0){
                dfs(j);
            }
        }
    }
    return;
}

int main(){

    adj[1][2] = 1;
    adj[1][3] = 1;
    adj[3][4] = 1;

    for(int i =0 ; i < 10 ; ++i){
        for (int j = 0 ; j < 10 ; ++j){
            if (adj[i][j] == 1 && visited[i] == 0) dfs(i);

        }
    }

    return 0;
}