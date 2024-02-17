#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int R, C;
vector<pair<int, int>> bird;
vector<vector<char>> lake, nextlake;
vector<vector<int>> visited;
vector<vector<int>> delta = {{-1,0}, {1,0},{0,-1}, {0,1}};
queue<pair<int, int>> candidates;

int main(){
    cin >> R >> C;
    lake = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<int>>(R, vector<int>(C,0));
    
    
    string s;
    for(int i = 0 ; i <R ; ++i){
        cin >> s;
        for(int j = 0 ; j < C ; ++j){
            if (s[j] == 'L'){
                bird.push_back({i,j});
                lake[i][j] = s[j];
            }
            else{
                lake[i][j] = s[j];
            }
        }
    }

    candidates.push(bird[0]);
    visited[bird[0].first][bird[0].second]= 1;
    nextlake = lake;

    int cnt = 0;
    while(true){

        // cout << endl;
        // for(auto ll : lake){
        //     for(auto l : ll) cout << l;
        //     cout << endl;
        // }
        // cout << cnt-1 << endl;

        if(lake[bird[1].first][bird[1].second] == '.'){ cout << (cnt)/2 ; break;}

        while(candidates.size()){
            pair<int, int> now = candidates.front(); candidates.pop();

            for(auto d : delta){
                int next_i = now.first + d[0];
                int next_j = now.second+ d[1];

                if (next_i >= 0 && next_j >= 0 && next_i < R && next_j < C){

                    if (visited[next_i][next_j] == 0){
                        
                        if(lake[next_i][next_j]=='.'){
                            candidates.push({next_i, next_j});
                            visited[next_i][next_j] = visited[now.first][now.second] + 1;
                        }
                        else{
                            nextlake[next_i][next_j] = '.';
                            visited[next_i][next_j] = visited[now.first][now.second] + 1;
                        }
                    }   
                }
            }
        }

   
        visited = vector<vector<int>>(R, vector<int>(C,0));
        candidates.push(bird[0]);
        visited[bird[0].first][bird[0].second]= 1;

        lake = nextlake;
        cnt++;
    }


    return 0;
}
