#include <iostream>
#include <vector>
#include <string>
#include <queue>

/*
5 7
3 4 1 2
1#10111
1101001
001*111
1101111
0011001
*/


using namespace std;

int N, M;
vector<vector<int>> room, nextroom;
pair<int, int> start;
pair<int, int> goal;

vector<vector<int>> visited;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(pair<int, int> here){

    visited[here.first][here.second] = 1;

    for(auto d : delta){
        int next_i = here.first + d[0];
        int next_j = here.second + d[1];
        if (next_i>=0 && next_j >= 0 && next_i < N && next_j < M){
            if (visited[next_i][next_j] == 0){
                if (room[next_i][next_j] == 0) dfs({next_i, next_j});
                else if (room[next_i][next_j] == 1 || room[next_i][next_j] == 2) nextroom[next_i][next_j] = 0;
            }
        }
    }
    return;
}

int main(){

    cin >> N >> M;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;
    start.first--, start.second--, goal.first--, goal.second--;

    room = vector<vector<int>>(N, vector<int>(M,0));
    visited = vector<vector<int>>(N, vector<int>(M,0));

    string s;
    for(int i = 0 ; i < N ; ++i){
        cin >> s;
        for(int j = 0 ; j < M ; ++j){

            if (s[j] != '#' && s[j] != '*')
                room[i][j] = (s[j]-'0');
            else
                room[i][j] = 2;
        }
    }

    nextroom = room;

    int cnt = 0 ;
    while(true){

        if (room[goal.first][goal.second] == 0){ cout << cnt<< endl; break;}

        dfs(start);
        room = nextroom;
        visited = vector<vector<int>>(N, vector<int>(M,0));

        cnt++;
    }

    return 0;
}