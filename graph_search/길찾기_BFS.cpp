#include <iostream>
#include <queue>

using namespace std;

/**
 7  
 0 0 0 0 0 0 0
 1 0 0 0 1 1 0
 0 0 0 0 1 0 7
 1 1 0 0 0 0 1
 0 1 1 0 0 0 0
 7 0 0 0 0 1 0
 1 1 1 1 1 1 1
 5 0
 2 6
*/

int main(){

    int N; // size
    cin >> N;

    // 지도
    vector<vector<int>> map(N, vector<int>(N,0)); 
    // 방문 후보지들을 기방문했는지 아닌지 표현하려고 만든 벡터
    vector<vector<int>> visited(N, vector<int>(N,0));
    // 거리를 나타내려고 만든 벡터, 이렇게 벡터를 별도로 만들 수 도 있지만, candidates Queue에 거리 정보를 넣어줄 수도 있을 것임
    vector<vector<int>> distance(N, vector<int>(N,0)); 
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> map[i][j];
        }
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    vector<pair<int, int>> delta = {{0,1},{1,0},{0,-1}, {-1,0}};

    queue<pair<int,int>> candidates;
    candidates.push(start);

    while( !candidates.empty()){

        pair<int, int> now = candidates.front();
        candidates.pop();

        if (now.first == end.first && now.second == end.second){
            cout << "Found it! (distance: " << distance[now.first][now.second] <<")" << endl;
            return 1;
        }
        else{
            for(auto d : delta){
                int next_i = now.first + d.first;
                int next_j = now.second + d.second;
                if (next_i >= 0 && next_i < N && next_j >=0 && next_j < N){
                    if(map[next_i][next_j] != 1 && visited[next_i][next_j] == 0){
                        distance[next_i][next_j] = distance[now.first][now.second]+1;
                        candidates.push({next_i, next_j});
                        visited[next_i][next_j] = 1;
                    }
                }
            }
        }
    }

    cout << "Failed: No exit!" << endl;
    return 0;
}