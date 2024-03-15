#include <bits/stdc++.h>

using namespace std;

int N;
int mn = 999999999;
vector<vector<int>> S;
deque<vector<int>> comb;

void make_combi(int start , vector<int> ret, int r){
    if (ret.size() == r){
        comb.push_back(ret);
        return;
    }
    for(int i = start+1; i < N ; ++i){
        ret.push_back(i);
        make_combi(i, ret, r);
        ret.pop_back();
    }
    return;
}

int main(){
    cin >> N;
    S = vector<vector<int>>(N, vector<int>(N,0));

    for(int i = 0 ; i < N ; ++i) 
        for(int j =0 ; j < N ; ++j) cin >> S[i][j];

    make_combi(-1, {}, N/2);

    while(comb.size()){

        auto s = comb.front();
        auto e = comb.back();

        comb.pop_front();
        comb.pop_back();

        int sum1 = 0;
        for(auto s1 : s){
            for(auto s2 : s){
                sum1 += S[s1][s2];
            }
        }

        int sum2 = 0;
        for(auto e1: e){
            for(auto e2: e){
                sum2 += S[e1][e2];
            }
        }

        
        if ( mn > abs(sum1-sum2)){
            mn = abs(sum1-sum2);
        }

    }

    cout << mn ;



    return 0;
}