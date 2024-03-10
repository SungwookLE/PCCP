#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> I;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> N;

    int d, reward;
    for(int i =0 ; i < N ; ++i){
        cin >> d >> reward;
        I.push_back({d,reward});
    }

    sort(I.begin(), I.end());

    int ret = 0;
    for(int i =0 ; i < N ; ++i){

        pq.push(I[i].second);
        while(pq.size() > I[i].first) pq.pop();
    }

    while(pq.size()){
        ret += pq.top(); pq.pop();
    }

    cout << ret;


    return 0;
}