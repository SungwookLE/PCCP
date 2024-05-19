#include <bits/stdc++.h>

using namespace std;
int N;
vector<tuple<int, int, int>> I;
vector<int> visited;
int DP[1001][1001];

int go(int STR, int INT){

    int& ret = DP[STR][INT];
    if(ret) return ret;

    int PNT= 0;
    vector<int> v;
    for(int i = 0 ; i < N ; ++i){
        int I_STR = get<0>(I[i]);
        int I_INT = get<1>(I[i]);
        int I_PNT = get<2>(I[i]);

        if (STR >= I_STR || INT >= I_INT){
            ret++;
            if(visited[i] == 0){
                visited[i] = 1;
                PNT += I_PNT;
                v.push_back(i);
            }
        }
    }

    if( PNT != 0)
        for(int p  = 0; p <= PNT; ++p){
            ret = max(ret, go(min(STR+p, 1000), min(INT+PNT-p,1000)));
        }

    for(auto here: v){
        visited[here] = 0;
    }

    return ret;
}

int main(){
    
    cin >> N;
    I = vector<tuple<int, int, int>>(N);
    visited = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i){
        cin >> get<0>(I[i]) >> get<1>(I[i]) >> get<2>(I[i]);
    }
    cout << go(1,1);


    return 0;
}