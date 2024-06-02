#include <bits/stdc++.h>

using namespace std;

// VIP 회원들의 좌석 번호들이 주어졌을 때, 사람들이 좌석에 앉는 서로 다른 방법의 가짓수를 구하는 프로그램

int N, M;
vector<int> S, visited;

int go(int id){
    int ret = 0;

    if (id == N+1){
        return 1;
    }

    for(int val = 1 ; val <= N ; ++val){
        if (visited[val] == 0 && S[id] == 0){
            visited[val] = 1;

            ret+=go(id+1);

            visited[val] = 0;
        }
    }


    return ret;
}

int main()
{
    cin >> N; // 1이상 40이하
    cin >> M; // 0이상 N이하
    S = vector<int>(N+1,0);
    visited = vector<int>(N+1,0);


    int id;
    for(int i =0 ; i < M ; ++i){
        cin >> id;
        S[id] = 1;
        visited[id] = 1;
    }

    cout << go(1);
     


    return 0;
}