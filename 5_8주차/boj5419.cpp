#include <bits/stdc++.h>

using namespace std;
int T;
int N;
vector<pair<int, int>> ISLAND;

int main(){

    cin >> T ;

    for(int i =0 ; i < T; ++i){
        cin >> N;
        ISLAND = vector<pair<int, int>>(N);
        for(int j =0 ; j < N ; ++j){
            cin >> ISLAND[j].first >> ISLAND[j].second;

            


        }
    }



    return 0;
}