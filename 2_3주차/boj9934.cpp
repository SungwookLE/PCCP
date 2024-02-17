#include <bits/stdc++.h>
using namespace std;

// 그래프의 중위방문

int K;
vector<int> order;
vector<vector<int>> ret;


void go (int s, int e , int level){
    if (s>e) return;
    if (s==e){
        ret[level].push_back(order[s]);
        return;
    }

    int mid = (s + e)/2;
    ret[level].push_back(order[mid]);
    go(s, mid-1, level+1);
    go(mid+1, e, level+1);

    return;
}

int main(){
    cin >> K;
    ret = vector<vector<int>>(K+1);

    int e = pow(2,K)-1;
    order = vector<int>(e,0);

    for(int i = 0 ; i < e ; ++i){
        cin >> order[i];
    }

    go(0, e-1, 0); // 0, 2, 0
    for(auto rr : ret){
        for(auto r: rr) cout << r << " ";
        cout << endl;
    }

    return 0;
}