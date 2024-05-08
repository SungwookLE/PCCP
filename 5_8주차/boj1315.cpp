#include <bits/stdc++.h>

using namespace std;

int N;
vector<tuple<int, int, int>> I;
vector<int> visited;
map<pair<int, int>, int> mp;

int go(int n, pair<int, int>Junku){

    if(n==N) return 0;

    int&ret = mp[Junku];
    if(ret) return ret;

    for(int i =0 ; i < N ; ++i){

        if(visited[i] == 0){
            int STR = get<0>(I[i]);
            int INT = get<1>(I[i]);
            int PNT = get<2>(I[i]);

            if (Junku.first >= STR || Junku.second >= INT){
                visited[i] = 1;

                if(Junku.first+PNT > Junku.second+PNT){
                    ret = go(n+1, {Junku.first+PNT, Junku.second})+1;
                }
                else{
                    ret = go(n+1, {Junku.first, Junku.second+PNT})+1;
                }

                visited[i] = 0;
            }
        }
    }

    return ret;
}


int main(){
    //준규가 깰 수 있는 퀘스트 개수의 최댓값을 구하는 프로그램
    // 처음에는 두개 스탯 모두 1
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N ;
    I = vector<tuple<int, int, int>>(N);
    visited = vector<int>(N,0);
    
    for(int i =0 ; i < N ; ++i){
        cin >> get<0>(I[i]) >> get<1>(I[i]) >> get<2>(I[i]);
    }
    sort(I.begin(), I.end());
    cout << go(0, {1,1});

    return 0;
}