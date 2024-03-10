#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<long long, long long>> D;
vector<long long> C;
int main(){

    cin >> N >> K;

    int M, V;
    for(int i =0 ; i < N ; ++i){
        cin >> M >> V;
        D.push_back({M,V});

    }

    sort(D.begin(), D.end(), [](auto a, auto b){
        if (a.first < b.first) return true;
        else if (a.first == b.first) return a.second > b.second;
        else return false;
    });

    C = vector<long long>(K,0);
    for(int i =0 ; i < K ; ++i){
        cin >> C[i];
    }

    sort(C.begin(), C.end());

    long long ret = 0;
    int j =0 ;
    priority_queue<long long> pq;
    for(int i =0 ; i < K ; ++i){

        while(j < N && D[j].first <= C[i]){
            pq.push(D[j++].second);
        }

        if (pq.size()){
            ret += pq.top(); pq.pop();
        }

    }

    cout << ret;




    return 0;
}