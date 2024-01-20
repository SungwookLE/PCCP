#include <iostream>

using namespace std;

/**
 7  
 0 0 0 0 0 0 0
 1 0 0 0 1 1 0
 0 0 0 0 1 0 0
 1 1 0 0 0 0 1
 0 1 1 0 0 0 0
 0 0 0 0 0 1 0
 1 1 1 1 1 1 1
 5 0
 2 6
*/


int N; // size
vector<pair<int, int>> delta = {{0,1},{-1,0},{0,-1}, {1,0}};
vector<vector<int>> map, dist; 
pair<int, int> start, goal;

void recurse(pair<int,int> now, bool& found){

    map[now.first][now.second] = 2;
    cout << now.first << " "<< now.second << endl;
    if(now.first == goal.first && now.second == goal.second){
        cout << "FOUND!!!!!" << endl;
        found = true;
        return;
    }
    else{
        for(auto d: delta ){
            int next_i = now.first + d.first;
            int next_j = now.second + d.second;
            if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N){
                if(map[next_i][next_j] == 0 && found != true){
                    pair<int, int> next = {next_i, next_j};
                    dist[next_i][next_j] = dist[now.first][now.second]+1;
                    recurse(next, found);
                }
            }
        }
    }
}

int main(){

    cin >> N;
    map = vector<vector<int>>(N, vector<int>(N,0));
    dist = vector<vector<int>>(N, vector<int>(N,0));

    // 지도
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> map[i][j];
        }
    }

    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;
    bool found = false;

    recurse(start, found);

    cout << dist[goal.first][goal.second] << endl;



}