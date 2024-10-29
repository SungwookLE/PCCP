#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> mmap,visited;
vector<int> delta[4] = {{-1,0},{1,0},{0,-1},{0,1}};

int go(pair<int, int> here){
    int ret = 0;

    if (here.first == 2 && here.second ==2){
        return 1;
    }

    for(auto d : delta){
        int next_i = here.first+d[0];
        int next_j = here.second+d[1];

        if (next_i < 0 || next_j < 0 || next_i >=3 || next_j >=3) continue;
        if (visited[next_i][next_j] == 1) continue;
        
        visited[next_i][next_j] = 1;
        ret+=go({next_i, next_j});
        visited[next_i][next_j] = 0;
    }

    return ret;

}


int main(){

    mmap.resize(3, vector<int>(3,0));
    visited.resize(3, vector<int>(3,0));


    for(int i =0 ; i < 3; ++i){
        for(int j =0 ; j < 3; ++j){
            cin >> mmap[i][j];
        }
    }

    cout << go({0,0});



    return 0;
}