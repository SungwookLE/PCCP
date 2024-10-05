#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> comb;
vector<int> W(9);


void make_combi(int start, vector<int>C){

    if (C.size() == 7){
        comb.push_back(C);
        return;
    }

    for(int i = start+1; i < 9; ++i){
        C.push_back(i);
        make_combi(i, C);
        C.pop_back();
    }

}

int main(){

    for(int i =0 ; i < 9 ; ++i){
        cin >> W[i];
    }

    make_combi(-1, {});

    for(auto c: comb){
        int sum = 0; 
        vector<int> Answer;

        for(auto cc: c){
            sum += W[cc];
            Answer.push_back(W[cc]);
        }

        if (sum == 100){
            sort(Answer.begin(), Answer.end());

            for(auto a : Answer){
                cout << a << "\n";
            }
            return 0;
        }
    }


    return 0;
}