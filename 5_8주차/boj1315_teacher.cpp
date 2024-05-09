#include <bits/stdc++.h>

using namespace std;

struct game{
    int x, y, c; 
};

int N;
vector<game> I;
int visited[1001];
int DP[1001][1001];

int go(pair<int, int>Junku){

    int&ret = DP[Junku.first][Junku.second];
    if(ret != -1) return ret; 

    ret = 0;
    int pnt = 0;
    vector<int> v;
    for(int i =0 ; i < N; ++i){
        int STR = I[i].x;
        int INT = I[i].y;
        int PNT = I[i].c;

        if (STR<=Junku.first || INT <= Junku.second){
            ret ++;
            if(visited[i] == 0){
                visited[i] = 1;
                pnt += PNT;
                v.push_back(i);
            }
        }
    }

    for(int p = 0 ; p <= pnt; ++p){
        ret = max(ret, go({min(Junku.first+p,1000), min(Junku.second+pnt-p,1000)}));
    }

    for(int here: v){
        visited[here] = 0;
    }

    return ret;
}


int main(){
    //준규가 깰 수 있는 퀘스트 개수의 최댓값을 구하는 프로그램
    // 처음에는 두개 스탯 모두 1
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    memset(DP, -1, sizeof(DP));
    cin >> N ;
    I = vector<game>(N);
    
    for(int i =0 ; i < N ; ++i){
        cin >> I[i].x >> I[i].y >> I[i].c;
    }

    cout << go({1,1});

    return 0;
}