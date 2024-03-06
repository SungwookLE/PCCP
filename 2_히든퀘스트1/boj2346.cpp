#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> q;

int main(){
    cin >> N;
    q = vector<pair<int, int>>(N);

    for(int i =0 ; i < N; ++i){
        q[i].first = i+1;   // idx
        cin >> q[i].second; // value
    } 


   
    return 0;
}