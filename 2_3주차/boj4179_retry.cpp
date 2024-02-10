#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int R, C;

#define INF 1000000000
vector<vector<char>>room;
pair<int, int> jihun;
queue<pair<int,int>> jihun_candidates, fire_candidates;
vector<vector<int>> jihun_visited;
vector<vector<int>> fire_visited;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};


bool isOutbound(int i, int j){
    return (i<0 || j <0 || i >= R || j >= C);
}

int main(){

    cin >> R >> C;
    room = vector<vector<char>>(R, vector<char>(C));
    jihun_visited = vector<vector<int>>(R, vector<int>(C,0));
    fire_visited = vector<vector<int>>(R, vector<int>(C,INF));

    vector<pair<int, int>> fire;
    for(int i = 0 ; i < R ; ++i){
        string s;
        cin >> s;
        for (int j = 0 ; j < C; ++j){
            room[i][j] = s[j];
            if (s[j] == 'J'){
                jihun = {i,j};
                room[i][j] = '.';
            } 
            else if (s[j] == 'F') fire.push_back({i,j});
        }
    }


    // 1. 불을 먼저 다 지펴라, 그리고 셀마다 불이 지나간 시간을 기록해라
    for(auto f: fire){
        fire_candidates.push(f);
        fire_visited[f.first][f.second] =1 ;
    }

    while(!fire_candidates.empty()){
        pair<int, int> fire_now = fire_candidates.front();
        fire_candidates.pop();
        for(auto d : delta){
            int fire_next_i = fire_now.first  + d[0];
            int fire_next_j = fire_now.second + d[1];

            if(!isOutbound(fire_next_i, fire_next_j)){
                if (room[fire_next_i][fire_next_j] == '.' && fire_visited[fire_next_i][fire_next_j] == INF){
                    fire_visited[fire_next_i][fire_next_j] = fire_visited[fire_now.first][fire_now.second] + 1;
                    fire_candidates.push({fire_next_i, fire_next_j});
                }
            }
        }
    }


    // 2. 지훈이는 불이 지나간 시간 보다 앞선 시간에만 지나간다면 무사히 통과할 수 있다는 의미다.
    // 이미, 불은 다 기록해두었으니, 지훈이만 잘 지나가게 하면 되겠다.
    jihun_candidates.push(jihun);
    jihun_visited[jihun.first][jihun.second] = 1;
    int ret =0;

    while(!jihun_candidates.empty()){

        pair<int, int> jihun_now = jihun_candidates.front();
        jihun_candidates.pop();

        if (jihun_now.first == 0 || jihun_now.second == 0 || jihun_now.first == R-1 || jihun_now.second == C-1){
            ret = jihun_visited[jihun_now.first][jihun_now.second];
            break;
        }


        for(auto d : delta){
            int jihun_next_i = jihun_now.first  + d[0];
            int jihun_next_j = jihun_now.second + d[1];

            if(!isOutbound(jihun_next_i, jihun_next_j)){
                if (room[jihun_next_i][jihun_next_j] == '.' && jihun_visited[jihun_next_i][jihun_next_j] == 0 && jihun_visited[jihun_now.first][jihun_now.second] + 1 < fire_visited[jihun_next_i][jihun_next_j]){
                    jihun_candidates.push({jihun_next_i, jihun_next_j});
                    jihun_visited[jihun_next_i][jihun_next_j] = jihun_visited[jihun_now.first][jihun_now.second]+1;
                }
            }
        }
    }

    if (ret == 0) cout << "IMPOSSIBLE";
    else cout << ret ;

    return 0;
}