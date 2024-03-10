#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> D;
int main(){
    cin >> N;

    int now, duration;

    for(int i =0 ; i < N ; ++i){
        cin >> now >> duration;
        D.push_back({now, duration});
    }

    sort(D.begin(), D.end());

    int ret = 0;
    for(int i =0 ; i < N; ++i){

        if (ret < D[i].first){

            ret = D[i].first;
        }

        ret += D[i].second;
    }
    cout << ret;

    return 0;
}