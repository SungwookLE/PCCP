#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> S;
int main(){
    cin >> n;

    int p, d;
    for(int i = 0; i < n ; ++i){
        cin >> p >> d;
        S.push_back({d, p}); // 날짜, 가격
    }

    sort(S.begin(), S.end()); // 오름차순 정렬

    long long ret = 0;

    priority_queue<int, vector<int> , greater<int>> pq; //top 에 제일 작은 값이 올라오게끔 priority_queue
    for(int i =0; i < n; ++i){

        pq.push(S[i].second);
        if (pq.size() > S[i].first){
            pq.pop(); //  day 안에 처리가 안되는 페이들은 제일 낮은값부터 pop()으로 제거
        }

    }

    while(pq.size()){ ret += pq.top(); pq.pop();}

    cout <<ret ;


    return 0;
}