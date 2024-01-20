#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> visited(n+1, vector<int>(m+1,0));
    vector<vector<int>> counted(n+1, vector<int>(m+1,-1));

    pair<int, int> horse, marine;

    cin >> horse.first >> horse.second;
    cin >> marine.first >> marine.second;

    queue<pair<int, int>> candidates;
    candidates.push(horse);
    counted[horse.first][horse.second] = 0;

    vector<pair<int, int>> deltas = {
                                     {-2,  1}, {-2, -1}, 
                                     {-1, -2}, { 1, -2}, {2, -1},
                                     { 2,  1}, {-1,  2}, {1,  2}
                                    };

    while(!candidates.empty()){

        pair<int, int> now = candidates.front();
        candidates.pop();

        if ((now.first == marine.first) && (now.second == marine.second)){
            break;
        }
        else{
            for(auto d : deltas){
                int next_i = now.first + d.first;
                int next_j = now.second + d.second;

                if(next_i > 0 && next_i < n && next_j > 0 && next_j < n){
                    if (visited[next_i][next_j] == 0){
                        candidates.push({next_i, next_j});
                        visited[next_i][next_j] = 1;
                        counted[next_i][next_j] = counted[now.first][now.second]+1;
                    }
                }
            }
        }
    }

    cout << counted[marine.first][marine.second] << endl;
}