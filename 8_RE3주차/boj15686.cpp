#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> city, home, chicken;

const int INF = 1E9;

int calChickenDist(vector<vector<int>> pick){

    int sum =0 ;
    for(auto h : home){
        int dist = INF;
        for(auto p : pick){
            int temp = abs(h[0]-p[0])+abs(h[1]-p[1]);
            if (temp < dist){
                dist = temp;
            }
        }
        sum += dist;
    }

    return sum;
}

int go(vector<vector<int>> pick, int idx){

    int ret = INF;

    

    if (pick.size()==M){
        return calChickenDist(pick);
    }

    for(int i = idx+1; i < chicken.size(); ++i){
        pick.push_back(chicken[i]);
        ret = min(ret, go(pick, i));
        pick.pop_back();
    }

    return ret;
}

int main(){
    cin >> N >> M;
    city = vector<vector<int>>(N, vector<int>(N,0));
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ;j < N ; ++j){
            cin >> city[i][j];
            if (city[i][j] == 1){
                home.push_back({i,j});
            }
            else if (city[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    // 치킨집 M개를 완전탐색하고, 탐색한 뒤 집과 치킨집의 거리의 합을 구하고 최소값을 출력

    cout << go({}, -1);

    return 0;
}