#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> Cards;
int ans = 0;

void make_combi(int start, vector<int> ret){


    if (ret.size() == 3){

        int sum = 0 ;
        for(auto r : ret){
            sum += r;
        }

        if (sum > M){
            ;
        }
        else{
            if (ans < sum) ans = sum;
        }

        return;
    }

    for(int i = start+1; i < N ; ++i){

        ret.push_back(Cards[i]);
        make_combi(i, ret);
        ret.pop_back();

    }

}

int main(){

    cin >> N >> M;
    Cards = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i){

        cin >> Cards[i];
    }


    make_combi(-1, {});
    cout << ans;




    return 0;
}