#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int M, N;
    cin >> M >> N;

    int fresh = 0;

    vector<vector<int>> boxes(M, vector<int>(N,0));
    queue<pair<int, int>> candidates;
    for(int i = 0 ; i < M ; ++i){
        for(int j =0 ; j < N; ++j){
            cin >> boxes[i][j];
            if (boxes[i][j] == 1){
                // 상한 귤은 각각이 시작 포인트가 된다.
                candidates.push({i,j});
                fresh +=1;
            }
            else if (boxes[i][j] == 0){
                fresh+=1;
            }
        }
    }


    vector<vector<int>> counted(M, vector<int>(N, 0));
    vector<pair<int, int>> deltas = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int last ;

    while(!candidates.empty()){

        auto now = candidates.front();
        candidates.pop();
        fresh-=1;
        last = counted[now.first][now.second];

        for(auto d : deltas){
            int next_i = now.first + d.first;
            int next_j = now.second + d.second;

            if(next_i >= 0 && next_i < M && next_j >= 0 && next_j < N){
                if (boxes[next_i][next_j] == 0 && counted[next_i][next_j] == 0){
                    candidates.push({next_i, next_j});
                    counted[next_i][next_j] = counted[now.first][now.second]+1;
                }
            }
        }
    }

    cout << "==상한귤==" << endl;
    for(auto row: counted){
        for (auto element: row)
            cout << element << " ";
        cout << endl;
    }
    cout << "=========" << endl;

    if (fresh > 0) cout << -1 << endl;
    else cout << last << endl;

    return 0;
}