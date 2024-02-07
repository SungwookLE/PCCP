#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> map_;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> visited;
int cnt;

void print(vector<vector<int>> v){

    for(auto vv:v){
        cout << "(" << map_[vv[0]][vv[1]]<<  ") ";
    }

}

void go(int i , int j, vector<vector<int>> v){

    if (i == 2 && j ==2){
        print(v);
        cout << endl;
        cnt ++;
        return;
    }

    for(auto d : delta){
        int next_i = i + d[0];
        int next_j = j + d[1];

        if(next_i >= 0 && next_j >= 0 && next_i < 3 && next_j <3){
            if (visited[next_i][next_j] == 0){
                visited[next_i][next_j] = 1;
                v.push_back({next_i, next_j});
                go(next_i, next_j, v);
                visited[next_i][next_j] = 0;
                v.pop_back();
            }
        }
    }
}

// {0, 0} -> {2, 2}
int main(){

    map_ = {{10,20,21},{70,90,12},{80,110,120}};
    visited = vector<vector<int>>(3, vector<int>(3,0));

    go(0,0, {{0,0}});
    cout << cnt << endl;




    return 0;
}