#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> SCV;
const vector<int> attack = {9,3,1};
vector<int> ret;

void go(vector<int> s, int cnt){

    int sz = s.size();
    for(int i = 2 ; i >= 0 ; --i){
        if (sz > i){
            s[i] -= attack[i];
            if(s[i]>0) ;
            else s.erase(s.begin()+i);
        }
    }

    if(s.empty()){
        ret.push_back(cnt);
        return;
    } 

    if (!s.empty()){
        do{
            go(s, cnt+1);
        }while(next_permutation(s.begin(), s.end()));
    }

    return;

}

int main(){
    cin >> N;
    SCV = vector<int>(N,0);

    for(int i = 0 ; i < N ; ++i) cin >> SCV[i];
    sort(SCV.begin(), SCV.end());

    do{
        go(SCV, 1);
    }while(next_permutation(SCV.begin(), SCV.end()));

    sort(ret.begin(), ret.end());
    cout << ret[0] << endl;

    return 0;
}