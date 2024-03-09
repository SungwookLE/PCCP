#include <bits/stdc++.h>

using namespace std;

int N, K;


vector<pair<int, int>> J;
vector<int> C;

int main(){

    cin >> N >> K;

    int M, V;
    for(int i = 0 ; i < N ; ++i){
        cin >> M >> V;
        J.push_back({M, V});
    } // J[0] = {가격, 무게}

    int c;
    for(int i = 0; i < K ; ++i){
        cin >> c;
        C.push_back(c);
    
    }
    sort(J.begin(), J.end()); // 오름차순 정렬
    sort(C.begin(), C.end()); // 오름차순 정렬

    priority_queue<long long> pq; // 가장 큰값이 top이 유지됨 , 즉 내림차순

    long long ret=0;
    int j =0 ; 

    // **벡터 배열들은 오름차순 정렬 되어 있어야 함
        // 넣을 수 있으면 후보에 다 올려둔 다음에, 가장 큰 값만 pick 해서 가방에 넣어주자.
        // 그 다음 가방은 후보들 중에 가장 큰 값을 넣어주면 된다.
    
    
    for(int i =0 ; i < K; ++i){

        // 조건을 만족하면 pq에 넣어줌
        while(j < N && J[j].first <= C[i]) pq.push(J[j++].second);
        
        // 만족하는 것중에 가장 큰 값을 +=top, pop;
        if (pq.size()){
            ret += pq.top(); pq.pop();
        }
    }
 
    cout << ret;

    return 0;
}