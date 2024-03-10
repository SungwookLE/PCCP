#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> D;

int main(){
    cin >> N;

    int s, e;
    for(int i =0 ; i < N ; ++i){
        cin >> s >> e;
        D.push_back({e,s});
    }

    sort(D.begin(), D.end());
    int now =0 ;
    int cnt =0 ;
    for(int i =0 ; i < N; ++i){

        if (now<=D[i].second){
            cnt ++;
            now = D[i].first;
        }


    }
    cout << cnt;

    return 0;
}