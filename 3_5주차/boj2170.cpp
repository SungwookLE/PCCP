#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    long long ret=0;

    int x, y;
    vector<pair<int, int>> L;
    for(int i =0 ; i < N ; ++i){
        cin >> x >> y;
        L.push_back({x,y});
    }

    sort(L.begin(), L.end());

    int l = L[0].first;
    int r = L[0].second;

    for(int i = 1; i < N ;++i){

        if ( r < L[i].first){
            ret += (r-l);
            l = L[i].first;
            r = L[i].second;
        }
        else if ( L[i].first <= r && r <= L[i].second)
            r = L[i].second;
    }

    ret += r-l;
    cout << ret ;


}